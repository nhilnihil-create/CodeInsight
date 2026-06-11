#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> divisor(ll x) {
  vector<ll> res;
  ll i = 1;
  for (; i * i <= x; ++i) {
    if (x % i != 0)
      continue;
    res.push_back(i);
    res.push_back(x / i);
  }
  --i;
  if (i * i == x)
    res.pop_back();
  return res;
}

int main() {
  ll n;
  cin >> n;

  auto ds = divisor(n);

  ll ans = 0;
  for (int i = 0; i < ds.size(); ++i) {
    ll m = ds[i] - 1;
    if (m > 0 && n / m == n % m)
      ans += m;
  }
  cout << ans << endl;
}