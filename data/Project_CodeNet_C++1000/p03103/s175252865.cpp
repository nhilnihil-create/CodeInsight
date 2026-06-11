#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, m; cin >> n >> m;
  map<ll,ll> M;
  ll ans = 0;
  rep(i,n) {
    ll a,b; cin >> a >> b;
    M[a]+=b;
  }
  for (auto p : M) {
    ll k = p.first;
    ll v = p.second;
    if (m - v >= 0) {
      ans += k * v;
      m -= v;
    } else {
      ans += k * m;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}