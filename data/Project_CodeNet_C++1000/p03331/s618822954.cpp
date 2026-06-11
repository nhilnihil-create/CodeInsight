#include <iostream>

int main() {
  int n;
  std::cin >> n;
  for(int i = 10; i <= n; i *= 10) {
    if(i == n) {
      std::cout << 10;
      return 0;
    }
  }
  int sum = 0;
  while(0 < n) {
    sum += n % 10;
    n /= 10;
  }
  std::cout << sum;
  return 0;
}
