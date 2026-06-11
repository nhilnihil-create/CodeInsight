#include <array>
#include <functional>
#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<std::vector<int>> G(N);
  for (int i = 0; i < N - 1; ++i) {
    int x, y;
    std::cin >> x >> y;
    G[x - 1].push_back(y - 1);
    G[y - 1].push_back(x - 1);
  }

  int mod = 1000000007;
  std::vector<std::array<long long, 2>> dp(N, std::array<long long, 2>({0, 0}));

  std::function<long long(int, int, int)> rec = [&](int v, int c, int pv) {
    if (dp[v][c] != 0)
      return dp[v][c];
    long long res = 1;
    for (auto &nv : G[v]) {
      if (nv == pv)
        continue;
      long long tmp = rec(nv, 0, v);
      if (c == 0)
        tmp = (tmp + rec(nv, 1, v)) % mod;
      res = (res * tmp) % mod;
    }
    return dp[v][c] = res;
  };

  long long res = (rec(0, 0, -1) + rec(0, 1, -1)) % mod;
  std::cout << res << std::endl;
}
