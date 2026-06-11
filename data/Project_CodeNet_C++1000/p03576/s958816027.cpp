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
using P = pair<ll, ll>;
const int INF = 1001001001;

int main(void){
  ll n, k;
  cin >> n >> k;
  vector<P> points(n);
  vector<ll> x(n), y(n);
  REP(i, n){
    cin >> x[i] >> y[i];
    points[i] = P(x[i], y[i]);
  }
  sort(ALL(x));
  sort(ALL(y));
  ll ans = (ll)(9e18);
  REP(y1, n) FORr(y2, n, y1){
    ll h = y[y2] - y[y1];
    REP(x1, n) FORr(x2, n, x1){
      ll w = x[x2] - x[x1];
      ll m = 0;
      REP(i, n){
        ll a = points[i].first;
        ll b = points[i].second;
        if(a < x[x1] || x[x2] < a || b < y[y1] || y[y2] < b) continue;
        m++;
      }
      if(m >= k) chmin(ans, h*w);
    }
  }
  cout << ans << endl;
  return 0;
}