#include <iostream>

int main() {
  long long X, Y;
  std::cin >> X >> Y;
  if (X % Y == 0) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << X << std::endl;
  }
  
}
