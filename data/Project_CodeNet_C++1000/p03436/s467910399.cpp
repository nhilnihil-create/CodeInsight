#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  int bc = 0;
  rep(i, h) {
    rep(j, w) {
      char x;
      cin >> x;
      s.at(i).at(j) = x;
      if (x == '#') {
        bc++;
      }
    }
  }
  vector<vector<int>> d(h, vector<int>(w, -1));
  d.at(0).at(0) = 0;
  queue<P> q;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    P c = q.front();
    q.pop();
    int cx = c.first;
    int cy = c.second;
    rep(i, 4) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
        continue;
      }
      if (s.at(ny).at(nx) == '#') {
        continue;
      }
      if (d.at(ny).at(nx) != -1) {
        continue;
      }
      d.at(ny).at(nx) = d.at(cy).at(cx) + 1;
      q.push(make_pair(nx, ny));
    }
  }
  int dist = d.at(h - 1).at(w - 1);
  if (dist == -1) {
    cout << -1 << endl;
    return 0;
  }
  int res = h * w - bc - (dist + 1);
  cout << res << endl;
  return 0;
}
