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
  i64 N, A, B;
  std::cin >> N >> A >> B;
  std::vector<i64> P;
  tools::read(P, N);
  std::cout << std::min({
    std::count_if(P.begin(), P.end(), [&A](const i64& P_i) { return P_i <= A; }),
    std::count_if(P.begin(), P.end(), [&A, &B](const i64& P_i) { return A < P_i && P_i <= B; }),
    std::count_if(P.begin(), P.end(), [&B](const i64& P_i) { return B < P_i; })
  }) << std::endl;
  return 0;
}