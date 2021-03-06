#pragma once

#pragma warning(push)
#include "F4SE/F4SE.h"
#include "RE/Fallout.h"

#include <fstream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include <AutoTOML.hpp>
#include <fmt/chrono.h>
#include <fmt/format.h>
#include <spdlog/sinks/basic_file_sink.h>
#pragma warning(pop)

#define DLLEXPORT __declspec(dllexport)

namespace F4SE
{
	namespace WinAPI
	{
		inline constexpr auto(MAX_COMPUTERNAME_LENGTH){ static_cast<std::uint32_t>(0x0F) };

		[[nodiscard]] bool(GetComputerName)(
			char* a_computerName,
			std::uint32_t* a_size) noexcept;
	}
}

namespace logger = F4SE::log;

namespace stl
{
	using F4SE::stl::emplace_vtable;
	using F4SE::stl::report_and_fail;
	using F4SE::stl::to_underlying;

#ifdef F4SE_SUPPORT_XBYAK
	void asm_replace(std::uintptr_t a_from, std::size_t a_size, std::uintptr_t a_to);
#endif
}

using namespace std::literals;

#include "version.h"

#include "Settings.h"
