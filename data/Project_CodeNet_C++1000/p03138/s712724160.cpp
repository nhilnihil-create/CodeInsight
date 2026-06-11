#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
 
typedef pair<ll, ll> P;
 
#define bit(n) (1LL << (n))
 
//#define int long long
 
#define all(v) v.begin(), v.end()
#define sortAl(v) sort(all(v))
#define sortAlr(v)          \
  sort(v.begin(), v.end()); \
  reverse(v.begin(), v.end())
 
#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)
 
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)
 
template <class T>
inline void chmax(T &a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T &a, T b) {
  a = std::min(a, b);
}
 
#define mod (ll)(1e9 + 7)
#define INF LLONG_MAX
 
#define MAX_DIGIT 45
 
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
 
  ll n, k;
  cin >> n >> k;
 
  vll a(n);
  vector<bitset<MAX_DIGIT>> bs(n);
  rep(i, n) {
    cin >> a[i];
    bs[i] = a[i];
  }
 
  if (k == 0) {
    cout << a[0] << endl;
    return 0;
  }
 
  vvll memo(MAX_DIGIT, vll(2));
 
  rep(d, MAX_DIGIT) {
    ll cnt = 0;
    rep(i, n) {
      if (bs[i][d]) {
        cnt++;
      }
    }
    memo[d][0] = cnt << d;
    memo[d][1] = (n - cnt) << d;
  }
 
  bitset<MAX_DIGIT> m;
  m = k;
 
  vvll dp(MAX_DIGIT+1, vll(2));
  ll d = MAX_DIGIT-1;
 
  while (m[d] == 0) {
    dp[d][0] = dp[d + 1][0] + memo[d][0];
    d--;
  }
  
  dp[d][0] = dp[d + 1][0] + max(memo[d][0], memo[d][1]);
  dp[d][1] = dp[d + 1][0] + memo[d][0];
  d--;
 
  for (; d >= 0; d--) {
    dp[d][1] = dp[d + 1][1] + max(memo[d][0], memo[d][1]);
 
    if (m[d]) {
      dp[d][0] = dp[d + 1][0] + memo[d][1];
      chmax(dp[d][1], dp[d + 1][0] + memo[d][0]);
    } else {
      dp[d][0] = dp[d + 1][0] + memo[d][0];
    }
  }
 
  cout << max(dp[0][0],dp[0][1]) << endl;
 
  return 0;
}