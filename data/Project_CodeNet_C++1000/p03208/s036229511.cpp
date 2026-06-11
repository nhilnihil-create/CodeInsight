#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(n, i) for(ll i = 0; i < n; ++i)

void solve(void){
  ll n, k; cin >> n >> k;
  vector<ll> vh(n, 0);
  rep(n, i) cin >> vh[i];

  sort(vh.begin(), vh.end());

  ll res = 1e9;
  for (ll i = 0; i + (k-1) < n; ++i) {
    res = min(res, vh[i+(k-1)] - vh[i]);
  }

  cout << res << endl;

}

int main(void) {
  solve();
  return 0;
}