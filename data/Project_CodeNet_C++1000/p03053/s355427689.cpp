#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int d[1010][1010];

void init() {
  rep(i, 1010) rep(j, 1010) d[i][j] = inf;
}

int h, w;
char a[1010][1010];

void bfs() {
  queue<pair<int, int>> q;
  rep(i, h) {
    rep(j, w) {
      if (a[i][j] == '#') {
        d[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    int y = q.front().first, x = q.front().second;
    q.pop();
    rep(k, 4) {
      int ry = y + dy[k], rx = x + dx[k];
      if (ry < 0 || ry >= h || rx < 0 || rx >= w) continue;
      if (chmin(d[ry][rx], d[y][x] + 1)) {
        q.push({ry, rx});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  init();

  cin >> h >> w;
  rep(i, h) {
    rep(j, w) {
      cin >> a[i][j];
    }
  }

  bfs();
  int ans = 0;
  rep(i, h) rep(j, w) chmax(ans, d[i][j]);
  cout << ans << '\n';




  
  return 0;
}