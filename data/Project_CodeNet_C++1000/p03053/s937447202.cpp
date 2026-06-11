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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) cin >> a[i];

  vector<vector<int>> d(h, vector<int>(w, INF));
  vector<pair<int, int>> blacks;
  rep(i, h) rep(j, w) {
    if (a[i][j] == '#') {
      blacks.emplace_back(i, j);
      d[i][j] = 0;
    }
  }

  int ans = 0;
  while (!blacks.empty()) {
    vector<pair<int, int>> new_blacks;
    for (auto& b : blacks) {
      int sh = b.first;
      int sw = b.second;
      rep(i, 4) {
        int nh = sh + dx[i];
        int nw = sw + dy[i];
        if (nh < 0 || nw < 0 || h <= nh || w <= nw) continue;
        if (a[nh][nw] == '#') continue;
        a[nh][nw] = '#';
        new_blacks.emplace_back(nh, nw);
      }
    }
    if (new_blacks.empty()) break;
    ans++;
    blacks = new_blacks;
  }

  cout << ans << endl;

  return 0;
}
