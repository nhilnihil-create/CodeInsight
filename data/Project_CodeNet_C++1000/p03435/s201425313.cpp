#include <iostream>

int main() {
  int c[3][3];
  for (int i = 0; i < 3; i++) {
    std::cin >> c[i][0] >> c[i][1] >> c[i][2];
  }
  int b1 = c[0][0], b2 = c[0][1], b3 = c[0][2];
  if (c[1][0] - b1 != c[1][1] - b2 || c[1][1] - b2 != c[1][2] - b3 || c[1][2] - b3 != c[1][0] - b1) {
    std::cout << "No" << "\n";
    return 0;
  }
  if (c[2][0] - b1 != c[2][1] - b2 || c[2][1] - b2 != c[2][2] - b3 || c[2][2] - b3 != c[2][0] - b1) {
    std::cout << "No" << "\n";
    return 0;
  }
  std::cout << "Yes" << "\n";
  return 0;
}