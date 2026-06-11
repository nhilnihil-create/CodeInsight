#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ina(x, n) rep(x_i,n) cin>>x[x_i]
#define outa(x, n) rep(x_i,n) cout<<x[x_i]<<" \n"[x_i==n-1]

typedef long long ll;
typedef vector<ll> vl;

int main() {
  ll n, k; cin >> n >> k;
  vl a(n), sums; ina(a,n);
  rep(i,n) {
    ll sum = 0;
    REP(j,i,n) {
      sum += a[j];
      sums.pb(sum);
    }
  }
  ll ans = 0, N = sums.size();
  for (int i = 40; i >= 0; i--) {
    ll t = (1LL<<i), cnt = 0;
    rep(j,N) {
      cnt += ((ans+t)&sums[j]) == (ans+t);
    }
    if (cnt >= k) ans += t;
  }
  cout << ans << endl;
  return 0;
}
