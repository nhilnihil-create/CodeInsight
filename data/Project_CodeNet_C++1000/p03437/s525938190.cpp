#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll x, ll y) {
  if (x < y) swap(x, y);
  while (y) swap(x %= y, y);
  return x;
}
int main() {
  ll x, y; cin >> x >> y;
  ll g = gcd(x, y);
  ll ans = x / g * y - x;
  if (ans > 0) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}