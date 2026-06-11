#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int N = 0;
  std::cin >> N;

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (i % 2 == 0) {
      continue;
    }
    int f = 0;
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) {
        f++;
      }
    }
    if (f == 8) {
      ans++;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}
