#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  int W = -1;
  vector<vector<char>> G(x,vector<char>(y));
  for (auto &v : G) {
    for (auto &c : v) {
      cin >> c;
      if (c == '.') W += 1;
    }
  }
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  queue<pair<int,int>> Q;
  vector<vector<int>> dist(x,vector<int>(y,-1));
  dist[0][0] = 0;
  Q.push({0,0});
  while (!Q.empty()) {
    auto p = Q.front();
    Q.pop();
    if (p == make_pair(x-1,y-1)) break;
    for (int i = 0; i < 4; i++) {
      int X = p.first+dx[i];
      int Y = p.second+dy[i];
      if (X < 0 || X >= x || Y < 0 || Y >= y) continue;
      if (G[X][Y] == '#') continue;
      if (dist[X][Y] != -1) continue;
      Q.push({X,Y});
      dist[X][Y] = dist[p.first][p.second] + 1;
    }
  }
  if (dist[x-1][y-1] == -1) cout << -1 << endl;
  else cout << W - dist[x-1][y-1] << endl;
}