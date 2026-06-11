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

typedef int64_t ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const ll INFL = (1LL<<60);
const double eps = (1e-9);

const ll mod = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> c(n);
  rep(i, n) cin >> c[i];

  vector<ll> sum(2e5+5, 0);
  vector<ll> dp(n+1, 0);
  dp[0] = 1;

  rep(i, n) {
    ll x = c[i];
    if (i != 0 && c[i] == c[i-1]) {
      dp[i+1] = dp[i];
      continue;  // 同じ値の間には区切りを入れない
    }
    sum[x] = (sum[x] + dp[i]) % mod;
    dp[i+1] = sum[x];
  }

  cout << dp[n] << endl;

  return 0;
}
