#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {-1, 1, 0, 0};
int main(void) {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  int white = 0;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '.') white++;
    }
  }
  vector<vector<int> > dist(h, vector<int>(w, -1));
  queue<pair<int, int> > q;
  q.push(make_pair(0, 0));
  dist[0][0] = 1;
  while (!q.empty()) {
    pair<int, int> current_pos = q.front();
    int current_y = current_pos.first;
    int current_x = current_pos.second;
    q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int next_y = current_y + dy[dir];
      int next_x = current_x + dx[dir];
      if (next_y < 0 || next_y >= h || next_x < 0 || next_x >= w) continue;
      if (s[next_y][next_x] == '#') continue;
      if (dist[next_y][next_x] >= 0) continue;
      dist[next_y][next_x] = dist[current_y][current_x] + 1;
      q.push(make_pair(next_y, next_x));
    }
  }
  if (dist[h - 1][w - 1] == -1) {
    cout << -1 << endl;
  } else {
    cout << white - dist[h - 1][w - 1] << endl;
  }
  return 0;
}