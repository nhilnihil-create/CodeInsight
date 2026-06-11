#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string S;
  std::cin >> S;

  int i = 700;
  for (auto &&s : S) {
    if (s == 'o') i += 100;
  }

  std::cout << i << std::endl;

  return 0;
}