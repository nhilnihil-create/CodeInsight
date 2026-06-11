#include <iostream>

using namespace std;

typedef long long ll;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

void solve () {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  if (a < b) {
    cout << "No" << '\n';
    return;
  }
  
  if (d < b) {
    cout << "No" << '\n';
    return;
  }
  
  if (b <= c) {
    cout << "Yes" << '\n';
    return;
  }

  c %= b;
  a %= b;
  d = gcd(b, d);

  // find least x s.t. a + kd = x, and x > c
  if (a > c) {
    cout << "No" << '\n';
    return;
  }

  ll k = (c - a) / d + 1;
  ll x = a + k * d;
  if (x >= b) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}
