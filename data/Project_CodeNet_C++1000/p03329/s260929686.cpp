#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
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

constexpr int INF = 1e9 + 5;
constexpr long long INFLL = 1LL << 60;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> op;
  for (int i = 1; pow(9, i) <= n; i++) {
    op.push_back(pow(9, i));
  }
  for (int i = 1; pow(6, i) <= n; i++) {
    op.push_back(pow(6, i));
  }
  op.push_back(1);

  sort(op.begin(), op.end());
  op.erase(unique(op.begin(), op.end()), op.end());

  sort(op.rbegin(), op.rend());

  // i 回目までの操作を使って j 引き出す場合の最小操作回数（j円ぴったりにできない場合はINF）
  vector<ll> dp(n + 1, INF);
  dp[0] = 0;
  for (auto& p : op) {
    for (int i = 0; i < n; i++) {
      if (dp[i] != INF && i + p <= n) {
        chmin(dp[i + p], dp[i] + 1);
      }
    }
  }

  cout << dp[n] << endl;

  return 0;
}
