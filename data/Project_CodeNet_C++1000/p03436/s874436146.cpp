#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
const int INF_INT = 2147483647;
const long long INF_LONG = 9223372036854775807;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int bfs(vector<vector<int>> &g, int h, int w) {
  queue<pair<int, int>> que;
  vector<int> vy = {0, 1, 0, -1};
  vector<int> vx = {1, 0, -1, 0};
  g[1][1] = 1;

  rep (i, 4) {
    if (g[1 + vy[i]][1 + vx[i]] == 0) {
      que.push(make_pair(1 + vy[i], 1 + vx[i]));
      g[1 + vy[i]][1 + vx[i]] = 2;
    }
  }
  while (!que.empty()) {
    int y, x;
    tie(y, x) = que.front();  que.pop();
    rep (i, 4) {
      if (g[y + vy[i]][x + vx[i]] == 0) {
        if (h == y + vy[i] && w == x + vx[i]) return g[y][x] + 1;
        que.push(make_pair(y + vy[i], x + vx[i]));
        g[y + vy[i]][x + vx[i]] = g[y][x] + 1;
      }
    }
  }

  return -1;
}

     
int main() {
  int h, w, s=0;  cin >> h >> w;
  vector<vector<int>> g(h + 2, vector<int>(w + 2, -2));
  for (int i=1; i<h+1; ++i) for (int j=1; j<w+1; ++j) {
    char c;  cin >> c;
    if (c == '.') {
      g[i][j] = 0;
      ++s;
    }
    else g[i][j] = -1;
  }

  int x = bfs(g, h, w);
  if (x == -1) cout << -1 << endl;
  else cout << s - x << endl;
}