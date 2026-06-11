#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else {
    return n * POW(n, m - 1);
  }
}

int main() {
  ll n, p, i, ans = 1, tmp = 0;
  cin >> n >> p;
  map<ll, ll> mp;
  i = 2;
  tmp = p;
  while (i * i <= p) {
    while (p % i == 0) {
      p /= i;
      ++mp[i];
    }
    ++i;
  }
  ++mp[p];
  for (auto p : mp) {
    if (p.second >= n) {

      ans *= POW(p.first, (p.second) / n);
    }
  }
  cout << ans << "\n";
  return 0;
}