#include <bits/stdc++.h>
#include <type_traits>

// lib/to_signed.hpp
#ifndef TO_SIGNED_HPP
#define TO_SIGNED_HPP


/*
usage:

std::uint_fast64_t i;
decltype(tools::to_signed(i)) // => std::int_fast64_t
*/

namespace tools {
  template <typename T>
  constexpr typename std::make_signed<T>::type to_signed(const T x) noexcept {
    return x;
  }
}

#endif

// main.cpp

int main() {
  std::string s;
  std::cin >> s;

  const std::int_fast64_t n = tools::to_signed(s.size());
  const char center = s[n / 2];
  std::int_fast64_t i;
  for (i = n / 2 - 1; i >= 0 && s[i] == center && s[n - i - 1] == center; --i);
  const std::int_fast64_t win = (n / 2 - 1) - i;
  std::cout << (n + 1) / 2 + win << std::endl;
  return 0;
}