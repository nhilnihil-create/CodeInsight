#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  ll g = gcd(n, m);

  ll ng = n / g;
  ll mg = m / g;

  bool ok = true;
  for (ll i = 0; i < g; i++) {
    if (s[ng * i] != t[mg * i]) {
      ok = false;
      break;
    }
  }

  if (ok) {
    cout << lcm(n, m) << endl;
  } else {
    puts("-1");
  }

  return 0;
}
