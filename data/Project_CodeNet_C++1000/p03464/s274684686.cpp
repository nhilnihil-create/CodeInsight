#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int k;
  cin >> k;
  
  vector<ll> a(k);
  for (int i = 0; i < k; i++) cin >> a.at(i);
  
  ll l = 0, r = 1e18;
  while (r - l > 1) {
    ll mid = (l + r) / 2, now = mid;
    for (int i = 0; i < k; i++) {
      now -= now % a.at(i);
    }
    if (now >= 2) r = mid;
    else l = mid;
  }
  ll x = r;
  
  l = 0;
  r = 1e18;
  while (r - l > 1) {
    ll mid = (l + r) / 2, now = mid;
    for (int i = 0; i < k; i++) {
      now -= now % a.at(i);
    }
    if (now > 2) r = mid;
    else l = mid;
  }
  ll y = l;
  
  if (x > y) cout << "-1\n";
  else cout << x << " " << y << '\n';
}