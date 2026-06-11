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

ll dp[100000];

int main(void){
  ll n;
  cin >> n;
  vector<ll> h(n);
  REP(i, n) cin >> h[i];
  REP(i, n) dp[i] = INF;
  dp[0] = 0;
  REP(i, n){
    if(i+1 < n) chmin(dp[i+1], dp[i]+abs(h[i+1]-h[i]));
    if(i+2 < n) chmin(dp[i+2], dp[i]+abs(h[i+2]-h[i]));
  }
  cout << dp[n-1] << endl;
  return 0;
}