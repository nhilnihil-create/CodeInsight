#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n;
  cin >> n;
  
  set<ll> s;
  ll now = n;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      s.insert(i);
      s.insert(n / i);
    }
  }
  s.erase(1);
  
  ll ans = 0;
  for (auto i : s) {
    i--;
    if (n / i == n % i) ans += i;
  }
  
  cout << ans << '\n';
}