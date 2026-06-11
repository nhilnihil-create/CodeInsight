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
  std::array<std::string, 3> ABC;
  tools::read(ABC);

  i64 answer = 0;
  for (i64 x = 0; x < N; ++x) {
    std::unordered_map<char, i64> map;
    for (i64 y = 0; y < 3; ++y) {
      ++map[ABC[y][x]];
    }
    answer += 3 - std::max_element(map.begin(), map.end(), [](const std::pair<char, i64>& x, const std::pair<char, i64>& y) { return x.second < y.second; })->second;
  }

  std::cout << answer << std::endl;
  return 0;
}