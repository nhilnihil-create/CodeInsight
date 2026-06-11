/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t H, W;
  cin >> H >> W;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<vector<bool>> open(H, vector<bool>(W, true));
  int64_t count_black = 0;
  for (int64_t i = 0; i < H; ++i) {
    string s;
    cin >> s;
    for (int64_t j = 0; j < W; ++j) {
      const char ch = s.c_str()[j];
      if (ch == '#') {
        open[i][j] = false;
        ++count_black;
      }
    }
  }
  vector<vector<int64_t>> distance(H, vector<int64_t>(W, kInf));
  distance[0][0] = 0;
  queue<Pair> q;
  q.emplace(0, 0);
  const int64_t d_nexts[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!q.empty()) {
    const Pair target = q.front();
    q.pop();
    for (const auto &d : d_nexts) {
      const Pair next(target.first + d[0], target.second + d[1]);
      if (next.first >= 0 && next.first < H && next.second >= 0 && next.second < W && open[next.first][next.second]) {
        if (distance[target.first][target.second] + 1 < distance[next.first][next.second]) {
          distance[next.first][next.second] = distance[target.first][target.second] + 1;
          q.emplace(next);
        }
      }
    }
  }
  int64_t result = 0;
  if (distance[H - 1][W - 1] == kInf) {
    result = -1;
  } else {
    result = H * W - count_black - (distance[H - 1][W - 1] + 1);
  }
  cout << result << endl;
  return 0;
}
