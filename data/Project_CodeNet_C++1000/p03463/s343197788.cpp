#include <iostream>

int main() {
  uint32_t N = 0, A = 0, B = 0;
  std::cin >> N >> A >> B;
  std::cout << ((B - A - 1) % 2 == 1 ? "Alice" : "Borys") << std::endl;
  return 0;
}