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
  vector<vector<ll>> s(m);
  REP(i, m){
    ll k;
    cin >> k;
    REP(j, k){
      ll a;
      cin >> a;
      a--;
      s[i].emplace_back(a);
    }
  }
  vector<ll>p(m);
  REP(i, m) cin >> p[i];

  ll ans = 0;
  REP(i, 1<<n){
    bool f = true;
    REP(j, m){
      ll count = 0;
      for(ll k : s[j]){
        if(i>>k & 1) count++;
      }
      if(count%2 != p[j]) f = false;
    }
    if(f) ans++;
  }
  cout << ans << endl;
  return 0;
}