#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
char maze[100][100];
int main() {
  int h, w;
  cin >> h >> w;
  vector<P> rec;

  rep(i,h) rep(j,w) {
    char c; cin >> c;
    maze[i][j] = c;
    if (c == '#') rec.push_back(make_pair(i,j));
  }

  int dx[4] = {0,-1,0,1}, dy[4] = {1,0,-1,0};
  rep(i,rec.size()) {
    int x = rec[i].first, y = rec[i].second;
    bool can = false;
    rep(j,4) {
      int nx = x + dx[j], ny = y + dy[j];
      if (0<=nx&&nx<h&&0<=ny&&ny<w&&maze[nx][ny]=='#') {can = true; break;}
    }
    if (!can) {cout << "No" << endl; return 0;}
  }
  cout << "Yes" << endl;
  return 0;
}