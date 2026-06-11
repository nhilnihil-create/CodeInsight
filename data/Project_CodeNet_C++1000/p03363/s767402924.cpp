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
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<int64_t> S(N + 1);
  map<int64_t, int64_t> counts;
  S[0] = 0;
  counts[0] = 1;
  for (int64_t i = 1; i <= N; ++i) {
    int64_t a;
    cin >> a;
    S[i] = a + S[i - 1];
    if (counts.find(S[i]) == counts.end()) {
      counts[S[i]] = 1;
    } else {
      ++counts[S[i]];
    }
  }

  int64_t result = 0;
  for (const auto m : counts) {
    const int64_t count = m.second;
    result += count * (count - 1) / 2;
  }
  cout << result << endl;
  return 0;
}
