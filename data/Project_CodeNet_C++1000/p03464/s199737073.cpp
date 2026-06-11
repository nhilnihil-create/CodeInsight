#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

// lib/detail/ceil_and_floor.hpp
#ifndef DETAIL_CEIL_AND_FLOOR_HPP
#define DETAIL_CEIL_AND_FLOOR_HPP

namespace tools {
  template <typename T>
  constexpr T floor(T lhs, T rhs);

  template <typename T>
  constexpr T ceil(T lhs, T rhs);

  template <typename T>
  constexpr T floor(const T lhs, const T rhs) {
    return
      lhs >= 0 && rhs >= 0 ?
        lhs / rhs :
      lhs < 0 && rhs >= 0 ?
        -ceil<T>(-lhs, rhs) :
      lhs >= 0 && rhs < 0 ?
        -ceil<T>(lhs, -rhs) :
        floor<T>(-lhs, -rhs);
  }

  template <typename T>
  constexpr T ceil(const T lhs, const T rhs) {
    return
      lhs >= 0 && rhs >= 0 ?
        (lhs - 1 + rhs) / rhs :
      lhs < 0 && rhs >= 0 ?
        -floor<T>(-lhs, rhs) :
      lhs >= 0 && rhs < 0 ?
        -floor<T>(lhs, -rhs) :
        ceil<T>(-lhs, -rhs);
  }
}

#endif

// lib/util.hpp
#ifndef UTIL_HPP
#define UTIL_HPP


typedef ::std::int_fast64_t i64;
typedef ::std::uint_fast64_t u64;
typedef ::std::int_fast32_t i32;
typedef ::std::uint_fast32_t u32;

namespace tools {
  template <typename T>
  void read(::std::istream& is, ::std::vector<T>& vector, const typename ::std::vector<T>::size_type size) {
    vector.reserve(size);
    ::std::copy_n(::std::istream_iterator<T>(is), size, ::std::back_inserter(vector));
  }
  template <typename T>
  void read(::std::vector<T>& vector, const typename ::std::vector<T>::size_type size) {
    ::tools::read(::std::cin, vector, size);
  }

  template <typename T, ::std::size_t N>
  void read(::std::istream& is, ::std::array<T, N>& array) {
    ::std::copy_n(std::istream_iterator<T>(is), N, array.begin());
  }
  template <typename T, ::std::size_t N>
  void read(::std::array<T, N>& array) {
    ::tools::read(::std::cin, array);
  }
}

#endif

// lib/floor.hpp
#ifndef FLOOR_HPP
#define FLOOR_HPP


/*
usage:

tools::floor(5, 3) // => 1 (i.e., floor(5 / 3))
*/

#endif

// lib/ceil.hpp
#ifndef CEIL_HPP
#define CEIL_HPP


/*
usage:

tools::ceil(5, 3) // => 2 (i.e., ceil(5 / 3))
*/

#endif

// main.cpp

int main() {
  i64 K;
  std::cin >> K;
  std::vector<i64> A;
  tools::read(A, K);

  std::reverse(A.begin(), A.end());
  std::pair<i64, i64> answer = std::make_pair(2, 2);
  for (const i64& A_i : A) {
    const i64 l = tools::ceil<i64>(answer.first, A_i);
    const i64 u = tools::floor<i64>(answer.second, A_i);
    if (l > u) {
      std::cout << -1 << std::endl;
      return 0;
    }
    answer = std::make_pair(l * A_i, (u + 1) * A_i - 1);
  }

  std::cout << answer.first << ' ' << answer.second << std::endl;
  return 0;
}