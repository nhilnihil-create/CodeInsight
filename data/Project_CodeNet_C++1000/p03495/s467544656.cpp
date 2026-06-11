#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<ll> v(200001, 0);
  rep(i, 0, n) {
    cin >> a[i];
    v[a[i]]++;
  }
  
  sort(v.rbegin(), v.rend());
  ll ans = 0;
  rep(i, 0, k) ans += v[i];
  
  cout << max(0LL, n-ans) << "\n";
}