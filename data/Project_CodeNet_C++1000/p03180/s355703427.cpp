#include <iostream>
const int MAX_N = 16;
const int MAX_M = 1 << 16;
long long sum[MAX_M], f[MAX_M];
int a[MAX_N][MAX_N];

int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) std::cin >> a[i][j];
  const int max = 1 << n;
  for (int s = 0; s < max; ++s) {
    for (int i = 0; i < n && (1 << i) <= s; ++i) {
      if (s >> i & 1) {
        for (int j = i + 1; j < n && (1 < j) <= s; ++j)
          if (s >> j & 1) sum[s] += a[i][j];
      }
    }
  }
  for (int s = 0; s < max; ++s)
    for (int j = s; j; j = (j - 1) & s)
      f[s] = std::max(f[s], f[s - j] + sum[j]);
  std::cout << f[max - 1];
  return 0;
}