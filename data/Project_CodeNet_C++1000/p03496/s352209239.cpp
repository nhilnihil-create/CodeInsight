#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

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

// main.cpp

int main() {
  i64 N;
  std::cin >> N;
  std::vector<i64> a;
  tools::read(a, N);

  const auto max_it = std::max_element(a.begin(), a.end());
  const auto min_it = std::min_element(a.begin(), a.end());
  const i64 max_index = std::distance(a.begin(), max_it) + 1;
  const i64 min_index = std::distance(a.begin(), min_it) + 1;
  if (*max_it >= 0 && std::abs(*min_it) <= std::abs(*max_it)) {
    std::cout << 2 * N - 1 << std::endl;
    std::cout << max_index << ' ' << N << std::endl;
    std::cout << max_index << ' ' << N << std::endl;
    std::cout << N << ' ' << N << std::endl;
    for (i64 i = 2; i <= N - 1; ++i) {
      std::cout << N << ' ' << i << std::endl;
      std::cout << N << ' ' << N << std::endl;
    }
  } else {
    std::cout << 2 * N - 1 << std::endl;
    std::cout << min_index << ' ' << 1 << std::endl;
    std::cout << min_index << ' ' << 1 << std::endl;
    std::cout << 1 << ' ' << 1 << std::endl;
    for (i64 i = N - 1; i >= 2; --i) {
      std::cout << 1 << ' ' << i << std::endl;
      std::cout << 1 << ' ' << 1 << std::endl;
    }
  }

  return 0;
}