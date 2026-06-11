#include <iostream>

int main() {
  // n is an integer between 1 and 10,000 (inclusive)
  // n is the length of 'true' elements of array a[10'000]
  int n, a[10'000], sum;
  std::cin >> n;

  sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    while (a[i] % 2 == 0) {
      a[i] /= 2;
      sum += 1;
    }
  }
  std::cout << sum;
  return 0;
}
