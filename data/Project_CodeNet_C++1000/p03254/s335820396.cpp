#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, x; cin >> n >> x;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  ll ans = 0;
  int i = 0;
  rep(i,n) {
    x -= a[i];
    if (x >= 0) ans++;
  }
  if (x > 0) ans--;
  cout << ans << endl;
  return 0;
}