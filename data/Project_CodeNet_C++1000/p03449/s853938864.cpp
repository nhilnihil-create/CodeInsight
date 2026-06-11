#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int a[2][n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[0][i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> a[1][i];
  }
  int res = -1;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j <= i; j++) {
      sum += a[0][j];
    }
    for (int k = i; k < n; k++) {
      sum += a[1][k];
    }
    if (res < sum) {
      res = sum;
    }
  }
  std::cout << res << "\n";
  return 0;
}