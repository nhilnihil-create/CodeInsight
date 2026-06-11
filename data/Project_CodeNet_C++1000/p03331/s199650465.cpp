#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main() {
  uint32_t N = 0;
  std::cin >> N;

  uint32_t base = 100000;
  uint32_t sum = 0;
  while (base != 0) {
    sum += N / base;
    N %= base;
    base /= 10;
  }

  std::cout << (sum == 1 ? 10 : sum) << std::endl;

  return 0;
}