#include <math.h>

#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

const int INF = 10000000;
typedef pair<int, int> P;

int main() {
  int H, W, N;
  cin >> H >> W;
  vector<vector<char>> field(H, vector<char>(W));
  vector<vector<int>> d(H, vector<int>(W));
  int white_num = 0;
  queue<P> que;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> field[i][j];
      d[i][j] = INF;
      if (field[i][j] == '#') {
        que.push(P(i, j));
        d[i][j] = 0;
      }
    }
  }
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  int ans = 0;
  while (que.size()) {
    P p = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (0 <= nx && nx < H && 0 <= ny && ny < W && field[nx][ny] != '#' &&
          d[nx][ny] == INF) {
        que.push(P(nx, ny));
        d[nx][ny] = d[p.first][p.second] + 1;
        ans = max(ans, d[nx][ny]);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
