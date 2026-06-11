#include <iostream>

int main() {
  int abc_like[] = { 111, 222, 333, 444, 555, 666, 777, 888, 999 };
  int n;  // 100 <= n <= 999 
  std::cin >> n;

  int abc_in = 0;
  int i = 0;
  while (abc_in == 0) {
    if (n <= abc_like[i]) {
      abc_in = abc_like[i];
    }
    ++i;
  }
  std::cout << abc_in << std::endl;

  return 0;
}
