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
  ll n;
  cin >> n;
  vector<ll> a(n+2);
  a[0] = a[n+1] = 0;
  REP(i, n) cin >> a[i+1];
  ll sum = 0;
  REP(i, n) sum += abs(a[i+1]-a[i]);
  sum += abs(a[n]);

  REP(i, n){
    ll ans = sum - (abs(a[i+1]-a[i])+abs(a[i+2]-a[i+1])) + abs(a[i+2]-a[i]);
    cout << ans << endl;
  }
  return 0;
}