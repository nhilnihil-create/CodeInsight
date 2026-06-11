#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string.h>
#include <cmath>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
  int H, W;
  cin >> H >> W;

  int ret = 0;
  char s[H][W];
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> s[i][j];
      if (s[i][j] == '#')
        ++ret;
    }
  }

  int d[H][W];
  memset(d, -1, sizeof(int) * H * W);
  queue<pair<int, int> > q;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    int cur_x = cur.second;
    int cur_y = cur.first;
    for (int i = -1; i < 2; ++i) {
      for (int j = -1; j < 2; ++j) {
        if (abs(i) == 1 && abs(j) == 1)
          continue;
        int next_x = cur_x + j;
        int next_y = cur_y + i;
        if (next_x >= 0 && next_x < W && next_y >= 0 && next_y < H) {
          if (s[next_y][next_x] == '.' && d[next_y][next_x] == -1) {
            d[next_y][next_x] = d[cur_y][cur_x] + 1;
            q.push(make_pair(next_y, next_x));
          }
        }
      }
    }
  }

  if (d[H - 1][W - 1] == -1) {
    cout << -1 << endl;
    return 0;
  }

  cout << H * W - d[H - 1][W - 1] - ret - 1 << endl;

  return 0;
}