#include <iostream>
#include <vector>

int main() {
  int n, d, x;
  std::cin >> n >> d >> x;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    sum += 1;
    for (int j = 1 + a; j <= d; j += a)
      ++sum;
  }

  std::cout << sum + x << std::endl;
}
