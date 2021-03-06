/*  =========================================================================
    fty_common_mlm_zconfig - C++ Wrapper Class fro zconfig

    Copyright (C) 2014 - 2020 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
*/

#pragma once

#include <czmq.h>
#include <string>

namespace mlm {
class ZConfig
{
private:
    // attributs
    zconfig_t* m_ptrConfig;


public:
    explicit ZConfig(const std::string& path);
    ~ZConfig();

    // methods

    /**
     * @brief Return the value of config entry or default value if the entry do not exist
     *
     * @param entry path
     * @param defaultValue value (empty string)
     */
    std::string getEntry(const std::string& entry, const std::string defaultValue = "") const;

    /**
     * @brief Set an entry in zconfig
     *
     * @param entry path
     * @param value value
     */
    void setEntry(const std::string& entry, const std::string value);

    /**
     * @brief Save a zconfig in a file
     *
     * @param path path to the file
     */
    void save(const std::string& path);
};

} // namespace mlm
