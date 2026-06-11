#include <iostream>

int main(int argc, char* argv[]) {
  int N, A, B;
  std::cin >> N >> A >> B;
  if ((B - A - 1) % 2) {  // 奇数
    std::cout << "Alice" << std::endl;
  } else {
    std::cout << "Borys" << std::endl;
  }
  return 0;
}