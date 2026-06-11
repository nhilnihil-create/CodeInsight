#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<std::vector<int>> a(N + 3, std::vector<int>(N + 3, 0));
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      std::cin >> a[i][j];

  int mod = 1000000007;

  std::vector<std::vector<long long>> dp(
      N + 3, std::vector<long long>((1 << N) + 3, 0));
  dp[0][0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int k = 0; k < 1 << N; ++k) {
      if (i != __builtin_popcount(k))
        continue;
      // int c = 0;
      // for (int j = 0; j < N; ++j)
      //   if (k & (1 << j))
      //     c += 1;
      // if (c != i)
      //   continue;

      for (int j = 0; j < N; ++j) {
        if (k & (1 << j))
          continue;
        dp[i + 1][k | (1 << j)] += a[i][j] * dp[i][k];
        dp[i + 1][k | (1 << j)] %= mod;
      }
    }
  }
  std::cout << dp[N][(1 << N) - 1] << std::endl;
}
