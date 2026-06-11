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
  map<int64_t, int64_t> m;
  for (int64_t i = 0; i < N; ++i) {
    int64_t a;
    cin >> a;
    if (m.find(a) == m.end()) {
      m[a] = 1;
    } else {
      ++m[a];
    }
  }
  int64_t result = 0;
  for (const auto a : m) {
    if (a.second >= a.first) {
      result += (a.second - a.first);
    } else {
      result += a.second;
    }
  }
  cout << result << endl;
  return 0;
}
