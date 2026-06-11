#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

// lib/util.hpp
#ifndef UTIL_HPP
#define UTIL_HPP


typedef std::int_fast64_t i64;
typedef std::uint_fast64_t u64;
typedef std::int_fast32_t i32;
typedef std::uint_fast32_t u32;

namespace tools {
  template <typename T>
  void read(std::vector<T>& vector, const typename std::vector<T>::size_type size) {
    vector.reserve(size);
    std::copy_n(std::istream_iterator<T>(std::cin), size, std::back_inserter(vector));
  }

  template <typename T, std::size_t N>
  void read(std::array<T, N>& array) {
    std::copy_n(std::istream_iterator<T>(std::cin), N, array.begin());
  }
}

#endif

// main.cpp

class alloy {
public:
  i64 height, width;
};

namespace std {
  std::istream& operator>>(std::istream& is, alloy& self) {
    return is >> self.height >> self.width;
  }
}

int main() {
  i64 N, H, W;
  std::cin >> N >> H >> W;
  std::vector<alloy> alloys;
  tools::read(alloys, N);

  std::cout << std::count_if(alloys.begin(), alloys.end(), [&H, &W](const alloy& alloy) {
    return W <= alloy.width && H <= alloy.height;
  }) << std::endl;
  return 0;
}