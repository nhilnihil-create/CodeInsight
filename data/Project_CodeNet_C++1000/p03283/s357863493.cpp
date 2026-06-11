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

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFLL = LLONG_MAX / 3;
const double eps = (1e-9);

/**
 * 二次元累積和を求める s[x][y] := [0, x) x [0, y) の長方形の区間の和
 * @param [in] base 元となる二次元データ (h * w)
 * @param [out] base を元に計算された累積和 ((h+1) * (w+1))
 */
vector<vector<int>> create_2d_cumulative_sum(const vector<vector<int>>& base) {
  int h = base.size();
  int w = base[0].size();
  vector<vector<int>> s(h+1, vector<int>(w+1, 0));
  rep(i, h) rep(j, w) {
    s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + base[i][j];
  }
  return s;
}

/**
 * 二次元累積和から指定された区間 [x1, x2) [y1, y2) の和を求める
 */
int get_value(const int& x1, const int& y1, const int& x2, const int& y2, const vector<vector<int>>& s) {
  return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> base(n, vector<int>(n, 0));
  rep(i, m) {
    int l, r; cin >> l >> r; l--; r--;
    base[l][r]++;
  }

  vector<vector<int>> w = create_2d_cumulative_sum(base);

  rep(i, q) {
    int l, r; cin >> l >> r; l--; r--;
    cout << get_value(l, l, r+1, r+1, w) << endl;
  }

  return 0;
}
