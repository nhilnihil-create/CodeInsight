#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> a(n);
  map<ll, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    mp[a.at(i)]++;
  }
  
  sort(a.begin(), a.end());
  
  vector<ll> x;
  for (ll i = 0; i < 40; i++) x.emplace_back(pow<ll>(2, i));
  
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (mp[a.at(i)] == 0) continue;
    ll keep = *upper_bound(x.begin(), x.end(), a.at(i)) - a.at(i);
    if (a.at(i) == keep && mp[keep] > 1) {
      ans++;
      mp[keep] -= 2;
    }
    else if (a.at(i) != keep && mp[keep] > 0) {
      ans++;
      mp[keep]--;
      mp[a.at(i)]--;
    }
  }
  
  cout << ans << '\n';
}