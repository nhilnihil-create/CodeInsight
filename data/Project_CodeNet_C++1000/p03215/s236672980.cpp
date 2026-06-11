#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  
  vector<ll> b;
  for (int i = 0; i < n; i++) {
    ll sum = 0;
    for (int j = i; j < n; j++) {
      sum += a.at(j);
      b.emplace_back(sum);
    }
  }
  
  ll ans = 0;
  for (ll i = 63; i >= 0; i--) {
    ll keep = pow(2, i), count = 0;
    for (int j = 0; j < b.size(); j++) {
      if (((ans + keep) & b.at(j)) == ans + keep) count++;
    }
    if (count >= k) ans += keep;
  }
  
  cout << ans << '\n';
}