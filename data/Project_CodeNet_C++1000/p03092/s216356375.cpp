
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <array>

template <class T, class U>
inline bool chmin(T &lhs, const U &rhs) {
  if (lhs > rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

template <class T, class U>
inline bool chmax(T &lhs, const U &rhs) {
  if (lhs < rhs) {
    lhs = rhs;
    return true;
  }
  return false;
}

constexpr int64_t inf = (1ll << 60);

int main() {
  int N;
  int A, B;
  std::cin >> N >> A >> B;
  std::vector<int> P(N);
  for (int &x: P) {
    std::cin >> x;
  }
  std::array<std::vector<int64_t>, 2> dp;
  dp.fill(std::vector<int64_t>(N + 1, inf));
  dp[0][0] = 0;
  for (int i = 0; i < N; ++i) {
    auto &cur = dp[i & 1];
    auto &next = dp[(i & 1) ^ 1];
    for (int j = 0; j <= N; ++j) {
      if(j < P[i]) {
        chmin(next[j], cur[j] + A);
        chmin(next[P[i]], cur[j]);
      }
      if(j > P[i]) {
        chmin(next[j], cur[j] + B);
      }
      cur[j] = inf;
    }
  }
  auto &ans = dp[N & 1];
  std::cout << *std::min_element(ans.begin(), ans.end()) << '\n';
  return 0;
}
