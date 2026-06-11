#include <algorithm>
#include <iostream>
#include <string>

int main() { int N, K;
  std::cin >> N >> K;
  std::cout << ((N + 1) / 2 >= K ? "YES" : "NO") << std::endl;
}

