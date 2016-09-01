/*
 * GNFlush SDN Controller GPL Source Code
 * Copyright (C) 2016, Greenet <greenet@greenet.net.cn>
 *
 * This file is part of the GNFlush SDN Controller. GNFlush SDN
 * Controller is a free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, , see <http://www.gnu.org/licenses/>.
 */

/******************************************************************************
*                                                                             *
*   File Name   : CRestRequest.cpp   *
*   Author      : bnc xflu           *
*   Create Date : 2016-7-21          *
*   Version     : 1.0           	 *
*   Function    : .           		 *
*                                                                             *
******************************************************************************/
#include "CRestRequest.h"
#include "CRestManager.h"

CRestRequest::CRestRequest()
{
}

CRestRequest::~CRestRequest()
{
}

CRestRequest::CRestRequest(std::string & raw)
{
	// 将string转换成可用的http
	parse(raw);

	// 验证http有效
	if (validate()) {
		// 获取method和path
		m_enHttpMethod = CRestDefine::getInstance()->getMethodFromStr(getHeaderFirstLine());
		CRestDefine::getInstance()->getPathFromStr(getHeaderFirstLine(), m_strPath);
	}
}