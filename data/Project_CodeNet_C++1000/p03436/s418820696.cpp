/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t H, W;
  cin >> H >> W;
  vector<vector<bool>> is_open(H, vector<bool>(W, true));
  int64_t count_black = 0;
  for (int64_t i = 0; i < H; ++i) {
    string s;
    cin >> s;
    for (int64_t j = 0; j < W; ++j) {
      const char ch = s.c_str()[j];
      if (ch == '#') {
        is_open[i][j] = false;
        ++count_black;
      }
    }
  }

  // BFS preparation
  queue<Pair> q;
  vector<vector<int64_t>> distances(H, vector<int64_t>(W, kInf));
  auto Update = [&](const Pair target, const int64_t distance) -> void {
    if (distances[target.first][target.second] != kInf) {
      return;
    }
    distances[target.first][target.second] = distance;
    q.emplace(target);
  };

  // BFS
  Update(Pair(0, 0), 0);
  const int64_t d_nexts[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  while (!q.empty()) {
    const Pair target = q.front();
    q.pop();
    for (const auto &d : d_nexts) {
      const int64_t next_row = target.first + d[0];
      const int64_t next_col = target.second + d[1];
      if (next_row >= 0 && next_row < H && next_col >= 0 && next_col < W) {
        if (is_open[next_row][next_col]) {
          Update(Pair(next_row, next_col), distances[target.first][target.second] + 1);
        }
      }
    }
  }

  int64_t result = 0;
  if (distances[H - 1][W - 1] == kInf) {
    result = -1;
  } else {
    result = H * W - count_black - (distances[H - 1][W - 1] + 1);
  }
  cout << result << endl;
  return 0;
}
