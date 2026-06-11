#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int r, d;
  std::vector<int> x(11);
  std::cin >> r >> d >> x.at(0);
  for (int i = 1; i <= 10; ++i) {
    x.at(i) = x.at(i - 1) * r - d;
  }

  for (int i = 1; i <= 10; ++i) 
    std::cout << x.at(i) << std::endl;
}
