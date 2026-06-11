/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int32_t neighbours[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t H, W;
  cin >> H >> W;
  vector<vector<bool>> goal_grid(H, vector<bool>(W, false));
  for (int32_t i = 0; i < H; ++i) {
    string s;
    cin >> s;
    for (int32_t j = 0; j < W; ++j) {
      goal_grid[i][j] = (s.c_str()[j] == '#');
    }
  }
  bool is_okay = true;
  for (int32_t r = 0; r < H; ++r) {
    for (int32_t c = 0; c < W; ++c) {
      if (goal_grid[r][c]) {
        bool found = false;
        for (const auto &neighbour : neighbours) {
          const int32_t next_r = r + neighbour[0];
          const int32_t next_c = c + neighbour[1];
          if (next_r >= 0 && next_r < H && next_c >= 0 && next_c < W) {
            if (goal_grid[next_r][next_c]) {
              found = true;
            }
          }
        }
        if (!found) {
          is_okay = false;
          break;
        }
      }
    }
  }
  if (is_okay) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
