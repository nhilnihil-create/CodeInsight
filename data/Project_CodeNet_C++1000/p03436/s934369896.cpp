#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

using P = pair<int, int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

inline bool is_inside(const int& h, const int& w, const int& u, const int& v) {
  return !(u < 0 || h <= u || v < 0 || w <= v);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector<vector<int>> dist(h, vector<int>(w, -1));
  dist[0][0] = 0;

  queue<P> q;
  q.push({0, 0});

  while (!q.empty()) {
    P u = q.front(); q.pop();
    rep(i, 4) {
      int nh = u.first + dx[i];
      int nw = u.second + dy[i];
      if (!is_inside(h, w, nh, nw)) continue;
      if (s[nh][nw] == '#') continue;
      if (dist[nh][nw] != -1) continue;
      dist[nh][nw] = dist[u.first][u.second] + 1;
      q.push({nh, nw});
    }
  }

  if (dist[h-1][w-1] == -1) {
    cout << -1 << endl;
    return 0;
  }

  int num_white = 0;
  rep(i, h) rep(j, w) if (s[i][j] == '.') num_white++;

  int ans = num_white - (dist[h-1][w-1] + 1);

  cout << ans << endl;

  return 0;
}
