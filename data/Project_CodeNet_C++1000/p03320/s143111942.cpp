#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int K; cin >> K;
  cout << 1 << endl;
  auto S = [](ll x) {
    ll res = 0;
    while (x) res += x % 10, x /= 10;
    return res;
  };
  ll x = 1, sx = 1;
  while (--K) {
    ll n = x + sx;
    ll m = x + sx * 10;
    if (S(m) * (n) > S(n) * (m)) sx *= 10;
    x += sx;
    cout << x << endl;
  }
  return 0;
}
