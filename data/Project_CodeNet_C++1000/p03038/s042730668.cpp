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
using P = pair<ll, ll>;

int main(void){
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  vector<P> d;
  REP(i, m){
    ll b, c;
    cin >> b >> c;
    d.emplace_back(c, b);
  }
  sort(ALL(a));
  sort(ALLr(d));
  ll ans = 0;
  ll i = 0;
  REP(j, m){
    ll c = d[j].first;
    ll b = d[j].second;
    ll k = 0;
    while(i < n && a[i] < c && k < b){
      ans += c;
      i++;
      k++;
    }
  }
  while(i < n){
    ans += a[i++];
  }
  cout << ans << endl;
  return 0;
}