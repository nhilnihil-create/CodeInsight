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
  std::array<i64, 4> degrees({0});
  for (i64 i = 0; i < 6; ++i) {
    i64 city;
    std::cin >> city;
    --city;
    ++degrees[city];
  }

  const i64 odd_degree = std::count_if(degrees.begin(), degrees.end(), [](const i64& degree) { return degree % 2 == 1; });

  std::cout << (odd_degree == 0 || odd_degree == 2 ? "YES" : "NO") << std::endl;
  return 0;
}