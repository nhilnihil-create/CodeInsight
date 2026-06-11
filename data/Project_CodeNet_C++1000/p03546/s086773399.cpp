/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t H, W;
  cin >> H >> W;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<vector<int64_t>> C(10, vector<int64_t>(10));
  for (int64_t a = 0; a < 10; ++a)
    for (int64_t b = 0; b < 10; ++b)
      cin >> C[a][b];

  vector<int64_t> dist(10, INT64_MAX);
  dist[1] = 0;
  priority_queue<Pair> q;
  q.emplace(dist[1], 1);
  while (!q.empty()) {
    const Pair p = q.top();
    q.pop();
    const int64_t c_dist = p.first;
    const int64_t c_num = p.second;
    for (int64_t n = 0; n < 10; ++n) {
      const int64_t next_dist = c_dist + C[n][c_num];
      if (n != c_num && n != 1 && next_dist < dist[n]) {
        dist[n] = next_dist;
        q.emplace(next_dist, n);
      }
    }
  }

  int64_t result = 0;
  for (int64_t i = 0; i < H; ++i) {
    for (int64_t j = 0; j < W; ++j) {
      int64_t a;
      cin >> a;
      if (a >= 0) {
        result += dist[a];
      }
    }
  }
  cout << result << endl;
  return 0;
}
