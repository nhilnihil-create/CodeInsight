#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string s[51];
int d[51][51];
int h, w;
bool flg = false;
typedef pair<int, int> P;

void bfs(int y, int x) {
  queue<P> que;
  P p;
  que.push(P(y, x));

  while (que.size()) {
    p = que.front(), que.pop();

    for (int i = 0; i < 4; i++) {
      int nx = p.second + dx[i], ny = p.first + dy[i];

      if (0 <= nx && nx < w && 0 <= ny && ny < h && s[ny][nx] != '#' &&
          d[ny][nx] == INF) {
        que.push(P(ny, nx));
        d[ny][nx] = d[p.first][p.second] + 1;
      }
    }
  }
}

int main() {
  int cnt = 0;
  cin >> h >> w;
  rep(i, h) cin >> s[i];
  rep(i, h) rep(j, w) if (s[i][j] == '#') cnt++;
  rep(i, h) rep(j, w) d[i][j] = INF;
  d[0][0] = 0;

  bfs(0, 0);
  int di = d[h - 1][w - 1];
  cout << (di == INF ? -1 : h * w - (di + 1 + cnt)) << endl;
  return 0;
}
