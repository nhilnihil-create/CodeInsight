/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;
  map<int64_t, int64_t> dp;
  vector<int64_t> steps;
  dp[0] = 0;
  dp[1] = 1;
  steps.emplace_back(1);
  for (int64_t c = 6; c <= N; c *= 6) {
    dp[c] = 1;
    steps.emplace_back(c);
  }
  for (int64_t c = 9; c <= N; c *= 9) {
    dp[c] = 1;
    steps.emplace_back(c);
  }
  sort(steps.begin(), steps.end());

  auto Dfs = [&](auto &&Func, const int64_t v) -> int64_t {
    if (dp.find(v) != dp.end()) {
      return dp[v];
    }
    int64_t res = kInf;
    for (auto step : steps) {
      if (v - step < 0) {
        break;
      }
      res = min(res, Func(Func, v - step) + 1);
    }
    dp[v] = res;
    return res;
  };
  cout << Dfs(Dfs, N) << endl;
  return 0;
}
