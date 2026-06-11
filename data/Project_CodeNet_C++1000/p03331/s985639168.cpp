#include <algorithm>
#include <iostream>

int sumDigits(int n) {
  int sum = 0;
  while (n > 1) {
    sum += n % 10;
    n /= 10;
  }
  sum += n;
  return sum;
}

int main(int argc, char *argv[]) {
  int N;
  std::cin >> N;
  int min = 1 << 20;
  for (int i = 1; i < N; ++i) {
    min = std::min(min, sumDigits(i) + sumDigits(N - i));
  }
  std::cout << min << std::endl;
}
