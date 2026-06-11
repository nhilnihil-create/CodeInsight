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

int main(void){
  ll n, k;
  cin >> n >> k;
  vector<ll> h(n);
  REP(i, n) cin >> h[i];
  vector<ll> dp(n, INF);
  dp[0] = 0;
  REP(i, n){
    REP(j, k){
      if(i+j+1 >= n) break;
      chmin(dp[i+j+1], dp[i]+abs(h[i+j+1]-h[i]));
    }
  }
  cout << dp[n-1] << endl;
  return 0;
}