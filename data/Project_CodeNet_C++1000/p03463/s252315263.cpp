#include <iostream>

int main(int argc, char *argv[]) {
  int N, A, B;
  std::cin >> N >> A >> B;
  std::cout << ((B - A) % 2 == 0 ? "Alice" : "Borys") << std::endl;
}
