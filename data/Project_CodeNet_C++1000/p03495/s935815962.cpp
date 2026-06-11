#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define all(v) v.begin(), v.end()

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  map<ll, ll> m;
  rep(i, 0, n) {
    cin >> a[i];
    m[a[i]]++;
  }
  
  if(m.size() <= k) {
    cout << 0 << "\n";
    return 0;
  }
  
  vector<ll> v;
  for(const auto& e : m)
    v.push_back(e.second);
  sort(all(v));
  ll lim = m.size()-k;
  ll ans = 0;
  rep(i, 0, lim) ans += v[i];
  
  cout << ans << "\n";
}