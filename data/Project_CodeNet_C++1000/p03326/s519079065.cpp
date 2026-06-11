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
  ll n, m;
  cin >> n >> m;
  vector<tuple<ll, ll, ll>> cakes;
  REP(i, n){
    ll x, y, z;
    cin >> x >> y >> z;
    cakes.emplace_back(x, y, z);
  }

  ll ans = 0;
  REP(i, 1<<3){
    ll a[] = {1, 1, 1};
    REP(j, 3) if(i & (1<<j)) a[j] = -1;
    vector<ll> s(n);
    REP(j, n){
      ll x, y, z;
      tie(x, y, z) = cakes[j];
      s[j] = a[0]*x+a[1]*y+a[2]*z;
    }
    sort(ALLr(s));
    ll sum = 0;
    REP(j, m) sum += s[j];
    chmax(ans, sum);
  }
  cout << ans << endl;
  return 0;
}