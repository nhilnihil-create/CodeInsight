#line 1 "/mnt/c/Users/leafc/dev/compro/lib/template.hpp"


#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define MM << " " <<

using namespace std;

template <class T> void say(bool val, T yes = "Yes", T no = "No") { cout << (val ? yes : no) << "\n"; }

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}


#line 2 "tmp.cpp"

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  REP(i, h) { cin >> grid[i]; }

  vector<vi> ans(h, vi(w, h + w + 1));
  queue<pair<int, int>> q;
  REP(i, h) {
    REP(j, w) {
      if (grid[i][j] == '#') {
        ans[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    auto p = q.front();
    int ci = p.first, cj = p.second;
    q.pop();
    REP(k, 4) {
      int ni = ci + dx[k], nj = cj + dy[k];
      if (0 <= ni && ni < h && 0 <= nj && nj < w && ans[ni][nj] > ans[ci][cj] + 1) {
        chmin(ans[ni][nj], ans[ci][cj] + 1);
        q.push({ni, nj});
      }
    }
  }

  int ret = 0;
  REP(i, h) {
    REP(j, w) { chmax(ret, ans[i][j]); }
  }
  cout << ret << endl;
  return 0;
}
