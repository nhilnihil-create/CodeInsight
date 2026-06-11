#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i=(ll)(a); i!=(ll)(b); i++)
#define RFOR(i, a, b) for(ll i=(ll)(a); i!=(ll)(b); i--)
#define REP(i, n) FOR(i, 0, n)

ll e(int i){
  if(i == 1) return 5;
  return 2*i + 1;
}

int main(){
  ll n, s; cin >> n >> s;
  ll x[n+1], c[n+1];
  FOR(i, 1, n+1) cin >> x[i];

  reverse(x+1, x+n+1);
  
  c[0] = 0;
  FOR(i, 1, n+1) c[i] = c[i-1] + x[i];

  ll ans = LLONG_MAX;
  FOR(k, 1, n+1){
    ll tp = 0;
    FOR(i, 1, (int)ceil(n*1./k)+1){
      tp += e(i) * (c[min(n, k*i)]-c[k*(i-1)]);
    }
    if(tp < 0) continue;
    ans = min(ans, tp + (k+n) * s);
  }

  cout << ans << endl;

  return 0;
}

