#include <iostream>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  int t[n], x[n], y[n];
  for (int i = 0; i < n; i++) {
    std::cin >> t[i] >> x[i] >> y[i];
  }
  if (t[0] % 2 != (x[0] + y[0]) % 2 || t[0] < (x[0] + y[0])) {
    std::cout << "No" << "\n";
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (abs(t[i] - t[i - 1]) % 2 != (abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1])) % 2 || abs(t[i] - t[i - 1]) < (abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]))) {
      std::cout << "No" << "\n";
      return 0;
    }
  }
  std::cout << "Yes" << "\n";
  return 0;
}