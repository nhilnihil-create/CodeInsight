#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> c[i];
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  ll ans = 0;
  rep(i,n) {
    ll s = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    ll t = c.end() - upper_bound(c.begin(), c.end(), b[i]);
    ans += s*t;
  }
  cout << ans << endl;
  return 0;
}