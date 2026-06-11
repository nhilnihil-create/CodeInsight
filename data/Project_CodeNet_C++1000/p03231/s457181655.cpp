#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  return (b == 0) ? a : gcd(b, a % b);
}

int main() {
  ll n, m;
  string s, t;
  cin >> n >> m >> s >> t;

  // gcd, lcm
  ll g = gcd(n, m);
  ll l = n * (m / g);

  int i = 0, v = 0, w = 0;
  while (v < s.size() && w < t.size()) {
    if (s[v] == t[w]) {
      ++i;
      v = i * n / g;
      w = i * m / g;
      continue;
    }
    cout << -1 << endl;
    return 0;
  }

  cout << l << endl;
}