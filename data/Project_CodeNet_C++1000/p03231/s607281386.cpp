#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}


int main() {
  ll n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  ll lcm = n * m / gcd(n, m);
  map<ll, char> mp;
  for (ll i = 0; i < n; ++i) {
    ll idx = i * lcm / n + 1;
    mp[idx] = s[(int)i];
  }

  for (ll i = 0; i < m; ++i) {
    ll idx = i * lcm / m + 1;
    auto it = mp.find(idx);
    if (it != mp.end() && mp[idx] != t[(int)i]) {
      puts("-1");
      return 0;
    }
  }
  cout << lcm << '\n';
  return 0;
}
