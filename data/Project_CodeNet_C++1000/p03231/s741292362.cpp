#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef long long ll;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

int main () {
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  map<ll, char> taken;
  for (ll i = 0; i < n; i++) {
    taken[i * m] = s[i];
  }

  for (ll i = 0; i < m; i++) {
    if (taken.count(i * n) && taken[i * n] != t[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << n * m / gcd(n, m) << endl;
}
