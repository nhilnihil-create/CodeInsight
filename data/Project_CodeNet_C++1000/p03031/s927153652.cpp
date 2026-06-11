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


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vector<bool>> con(n, vector<bool>(m, false));  // n 番目のスイッチが m 番目の電球に繋がっているか？
  rep(i, m) {
    int k;
    cin >> k;
    rep(j, k) {
      int s; cin >> s; s--;
      con[s][i] = true;
    }
  }
  vector<int> p(m);
  rep(i, m) cin >> p[i];

  auto f = [&](const vector<int>& n_on) {
    rep(i, m) {
      if (p[i] != (n_on[i] % 2)) return false;
    }
    return true;
  };

  ll ans = 0;

  for (int bit = 0; bit < (1 << n); bit++) {
    vector<int> n_on(m, 0);  // 各電球の on の数
    rep(i, n) {
      if ((bit >> i) & 1) {
        // i 番目のスイッチが on になっている
        rep(j, m) {
          if (con[i][j]) n_on[j]++;
        }
      }
    }
    if (f(n_on)) ans++;
  }

  cout << ans << endl;

  return 0;
}
