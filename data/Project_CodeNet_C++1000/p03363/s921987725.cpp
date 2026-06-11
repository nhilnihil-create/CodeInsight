#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);

  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> wa(n+1, 0);
  map<ll, ll> m;
  m[0]++;
  rep(i, 0, n) {
    cin >> a[i];
    wa[i+1] = wa[i]+a[i];
    m[wa[i+1]]++;
  }
  
  ll ans = 0;
  for(const auto& e : m) {
    ll x = e.second;
    if(x >= 2) {
      ans += (x*(x-1))/2;
    }
  }
  cout << ans << "\n";
}