#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

ll dp[100005][3];

int main(void){
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), c(n);
  REP(i, n) cin >> a[i] >> b[i] >> c[i];
  REP(i, n){
    dp[i+1][0] = max(dp[i][1]+b[i], dp[i][2]+c[i]);
    dp[i+1][1] = max(dp[i][0]+a[i], dp[i][2]+c[i]);
    dp[i+1][2] = max(dp[i][0]+a[i], dp[i][1]+b[i]);
  }
  ll ans = 0;
  REP(i, 3) chmax(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}