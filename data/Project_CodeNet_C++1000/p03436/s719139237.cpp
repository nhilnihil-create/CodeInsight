#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using GraphI = vector<vector<int>>;
using GraphC = vector<vector<char>>;

int main() {
  int h, w;
  cin >> h >> w;
  GraphC g(h, vector<char>(w, '#'));
  int white = 0;
  rep(y, h) {
    rep(x, w) {
      cin >> g[y][x];
      if (g[y][x] == '.') white++;
    }
  }

  GraphI d(h, vector<int>(w, -1));
  d[0][0] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));

  int dy[4] = {-1, 0, 1, 0};
  int dx[4] = {0, 1, 0, -1};

  while (!q.empty()) {
    pair<int, int> now = q.front();
    q.pop();

    rep(i, 4) {
      int ny, nx;
      ny = now.first + dy[i];
      nx = now.second + dx[i];
      if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      if (g[ny][nx] == '#') continue;
      if (d[ny][nx] != -1) continue;
      d[ny][nx] = d[now.first][now.second] + 1;
      q.push(make_pair(ny, nx));
    }
  }

  int goal = d[h - 1][w - 1];
  if (goal == -1)
    cout << -1 << endl;
  else
    cout << white - (d[h - 1][w - 1] + 1) << endl;

  return 0;
}
