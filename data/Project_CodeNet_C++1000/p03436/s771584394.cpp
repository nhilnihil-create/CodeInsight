#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<string> maze(h);
  rep(i, h) cin >> maze[i];

  queue<pair<int, int>> q;
  q.push({0, 0});

  vector<vector<int>> d(h, vector<int>(w, INF));
  d[0][0] = 0;

  while (!q.empty()) {
    pair<int, int> p = q.front(); q.pop();
    int ch = p.first;
    int cw = p.second;
    rep(i, 4) {
      int nh = ch + dy[i];
      int nw = cw + dx[i];
      if (nh < 0 || nh >= h || nw < 0 || nw >= w) continue;
      if (maze[nh][nw] == '#') continue;
      if (d[nh][nw] != INF) continue;
      d[nh][nw] = d[ch][cw] + 1;
      q.push({nh, nw});
    }
  }

  if (d[h-1][w-1] == INF) {
    cout << -1 << endl;
    return 0;
  }

  int n_white = 0;
  rep(i, h) rep(j, w) if (maze[i][j] == '.') n_white++;

  cout << n_white - d[h-1][w-1] - 1 << endl;

  return 0;
}
