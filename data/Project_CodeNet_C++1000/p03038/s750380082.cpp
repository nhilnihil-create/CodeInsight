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
  cin >> N >> M;
  map<int64_t, int64_t> m;

  auto Add = [&](const int64_t value) {
    if (m.find(value) == m.end()) {
      m[value] = 1;
    } else {
      ++m[value];
    }
  };

  for (int64_t i = 0; i < N; ++i) {
    int64_t a;
    cin >> a;
    Add(a);
  }
  for (int64_t i = 0; i < M; ++i) {
    int64_t b, c;
    cin >> b >> c;
    while (b > 0) {
      auto itr = m.begin();
      const int64_t reduce = min(itr->second, b);
      if (c <= itr->first) {
        break;
      }
      b -= reduce;
      itr->second -= reduce;
      if (itr->second == 0) {
        m.erase(itr);
      }
      if (m.find(c) == m.end()) {
        m[c] = reduce;
      } else {
        m[c] += reduce;
      }
    }
  }
  int64_t result = 0;
  for (auto a : m) {
    result += a.first * a.second;
  }
  cout << result << endl;
  return 0;
}
