#include <iostream>

int main() {
  int n;
  std::cin >> n;
  long long a[n];
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      sum++;
    }
  }
  std::cout << sum << "\n";
  return 0;
}