#include <iostream>

// 1 2 3 => -1
// 5 4 3 => 1
// 7 8 9 => -1
// 17 16 15 => 1

// 1 3 5 => -2
// 8 6 6 => 2

int main(int argc, char *argv[]) {
  long long a, b, c, k;
  std::cin >> a >> b >> c >> k;
  long long ans = a - b;
  if (k % 2 == 0)
    std::cout << ans << std::endl;
  else
    std::cout << -ans << std::endl;
}
