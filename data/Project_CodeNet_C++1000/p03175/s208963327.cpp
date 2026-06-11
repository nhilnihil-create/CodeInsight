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
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  int mod = 1000000007;

  std::vector<std::array<long long, 2>> dp(N, std::array<long long, 2>({0, 0}));

  std::function<void(int, int)> dfs = [&](int v, int pv) {
    dp[v][0] = dp[v][1] = 1;
    for (auto &nv : G[v]) {
      if (nv == pv)
        continue;
      dfs(nv, v);
      dp[v][1] = (dp[v][1] * dp[nv][0]) % mod;
      dp[v][0] = (dp[v][0] * (dp[nv][0] + dp[nv][1])) % mod;
    }
  };
  dfs(0, -1);
  long long res = (dp[0][0] + dp[0][1]) % mod;
  std::cout << res << std::endl;
}
