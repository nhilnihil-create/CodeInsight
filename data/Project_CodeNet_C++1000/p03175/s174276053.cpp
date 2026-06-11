#include <array>
#include <functional>
#include <iostream>
#include <vector>

template <class T> inline void chmul(T &a, const T &b, int mod) {
  a = (a * b) % mod;
}

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

  std::function<long long(int, int, int)> rec = [&](int v, int pv, int c) {
    if (dp[v][c] != 0)
      return dp[v][c];
    long long res = 1;
    for (auto &nv : G[v]) {
      if (nv == pv)
        continue;
      if (c == 1)
        chmul(res, rec(nv, v, 0), mod);
      else
        chmul(res, rec(nv, v, 0) + rec(nv, v, 1), mod);
    }
    return dp[v][c] = res;
  };

  long long res = (rec(0, -1, 0) + rec(0, -1, 1)) % mod;
  std::cout << res << std::endl;
}
