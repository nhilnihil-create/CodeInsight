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

  int64_t N, M;
  cin >> N;
  unordered_map<int64_t, int64_t> counts;
  for (int64_t i = 0; i < N; ++i) {
    int64_t d;
    cin >> d;
    if (counts.find(d) == counts.end()) {
      counts[d] = 1;
    } else {
      ++counts[d];
    }
  }
  cin >> M;
  vector<int64_t> T(M);
  for (int64_t i = 0; i < M; ++i) {
    int64_t d;
    cin >> d;
    if (counts.find(d) == counts.end() || counts[d] == 0) {
      cout << "NO" << endl;
      return 0;
    } else {
      --counts[d];
    }
  }
  cout << "YES" << endl;
  return 0;
}
