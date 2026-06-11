#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};
int main(void) {
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  queue<pair<int, int> > q;
  vector<vector<int> > dist(h, vector<int>(w, -1));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        q.push(make_pair(i, j));
        dist[i][j] = 0;
      }
    }
  }
  int ans;
  while (!q.empty()) {
    pair<int, int> pos = q.front();
    int cur_y = pos.first;
    int cur_x = pos.second;
    q.pop();
    ans = dist[cur_y][cur_x];
    for (int dir = 0; dir < 4; dir++) {
      int next_y = cur_y + dy[dir];
      int next_x = cur_x + dx[dir];
      if (next_y < 0 || next_y >= h || next_x < 0 || next_x >= w) continue;
      if (dist[next_y][next_x] >= 0) continue;
      q.push(make_pair(next_y, next_x));
      dist[next_y][next_x] = dist[cur_y][cur_x] + 1;
    }
  }
  cout << ans << endl;
  return 0;
}