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

/**
 * 二次元累積和を求める s[x][y] := [0, x) x [0, y) の長方形の区間の和
 * 注意：半開区間になっている
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
  vector<vector<int>> t(n, vector<int>(n, 0));

  rep(i, m) {
    int l, r; cin >> l >> r; l--, r--;
    t[l][r]++;
  }

  auto csum = create_2d_cumulative_sum(t);

  rep(i, q) {
    int l, r; cin >> l >> r; l--, r--;
    int x = get_value(l, l, r+1, r+1, csum);
    cout << x << endl;
  }

  return 0;
}
