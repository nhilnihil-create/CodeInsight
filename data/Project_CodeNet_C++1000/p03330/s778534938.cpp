#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = int64_t;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, c;
  cin >> n >> c;
  vector<vector<int>> costs(vector<vector<int>>(c, vector<int>(c)));
  rep(i, c) rep(j, c) cin >> costs[i][j];

  vector<vector<int>> grids(vector<vector<int>>(n, vector<int>(n)));
  rep(i, n) rep(j, n) {
    cin >> grids[i][j];
    grids[i][j]--;
  }

  vector<int> c1(c, 0), c2(c, 0), c3(c, 0);

  rep(i, c) {
    rep(h, n) rep(w, n) {
      if ((h + w) % 3 == 0) c1[i] += costs[grids[h][w]][i];
      if ((h + w) % 3 == 1) c2[i] += costs[grids[h][w]][i];
      if ((h + w) % 3 == 2) c3[i] += costs[grids[h][w]][i];
    }
  }

  int ans = INF;
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < c; j++) {
      if (i == j) continue;
      for (int k = 0; k < c; k++) {
        if (i == k || j == k) continue;
        chmin(ans, c1[i] + c2[j] + c3[k]);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
