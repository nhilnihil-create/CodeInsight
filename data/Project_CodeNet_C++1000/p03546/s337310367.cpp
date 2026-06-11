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

  int64_t H, W;
  cin >> H >> W;
  vector<vector<int64_t>> distance(10, vector<int64_t>(10, kInf));
  for (int64_t r = 0; r < 10; ++r) {
    for (int64_t c = 0; c < 10; ++c) {
      cin >> distance[r][c];
    }
  }

  for (int64_t i = 0; i < 10; ++i) {
    distance[i][i] = 0;
  }
  for (int64_t k = 0; k < 10; ++k) {
    for (int64_t i = 0; i < 10; ++i) {
      for (int64_t j = 0; j < 10; ++j) {
        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
      }
    }
  }

  int64_t result = 0;
  for (int64_t r = 0; r < H; ++r) {
    for (int64_t c = 0; c < W; ++c) {
      int64_t a;
      cin >> a;
      if (a >= 0) {
        result += distance[a][1];
      }
    }
  }
  cout << result << endl;
  return 0;
}
