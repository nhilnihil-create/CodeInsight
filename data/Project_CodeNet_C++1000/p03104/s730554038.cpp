#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x) {
  ll res = x, y = x;
  if (x % 2 == 0) {
    y -= 1;
  } else {
    res = 0;
  }
  res ^= y / 2 % 2 == 0 ? 1 : 0;
  return x <= 0 ? 0 : res;
}

int main() {
  ll a, b;
  cin >> a >> b;
  ll ans = f(a - 1) ^ f(b);
  cout << ans << endl;
}