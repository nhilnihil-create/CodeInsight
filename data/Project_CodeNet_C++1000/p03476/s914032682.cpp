#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isprime(ll x) {
  if (x <= 1) return false;
  for (ll i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}

int main() {
  const ll n = 2e5;
  vector<ll> s(n);
  for (ll i = 1; i < n; i++)
    s[i] = s[i - 1] + ((i & 1) && isprime(i) && isprime((i + 1) / 2));
  ll q;
  cin >> q;
  for (ll i = 0; i < q; i++) {
    ll l, r;
    cin >> l >> r;
    cout << s[r] - s[l - 1] << endl;
  }
  return 0;
}
