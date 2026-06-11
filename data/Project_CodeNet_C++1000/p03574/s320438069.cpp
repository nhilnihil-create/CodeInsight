#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

template <typename F>
void forNeighbor8(int h, int w, int x, int y, F f) {
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      if (dx != 0 || dy != 0) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
          f(nx, ny);
        }
      }
    }
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> grid(H);
  rep(i, H) { cin >> grid[i]; }

  rep(i, H) rep(j, W) {
    if (grid[i][j] == '.') {
      int cnt = 0;
      forNeighbor8(H, W, i, j, [&](int x, int y) {
        if (grid[x][y] == '#') {
          cnt++;
        }
      });
      grid[i][j] = cnt + '0';
    }
  }

  rep(i, H) { cout << grid[i] << "\n"; }

  return 0;
}