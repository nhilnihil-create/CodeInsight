#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(n, i) for(ll i = 0; i < n; ++i)

void solve(void){
  ll n; cin >> n;
  vector<ll> v(n, 0);
  rep(n, i) cin >> v[i];

  ll res = 0;
  rep(n, i) {
    ll bit = v[i];
    ll cnt = 0;
    while (bit % 2 == 0) {
      ++cnt;
      bit >>= 1;
    }
    res += cnt;
  }

  cout << res << endl;
}

int main(void) {
  solve();
  return 0;
}
