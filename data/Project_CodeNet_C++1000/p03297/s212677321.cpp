#include <iostream>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  if (min(a, b) == 0) {
    return max(a, b);
  }
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}

bool solve(ll a, ll b, ll c, ll d) {
  if (a < b) {
    return false;
  }
  if (b > d) {
    return false;
  }
  if (b <= c) {
    return true;
  }
  ll g = gcd(b, d);
  if (b - g + a % g > c) {
    return false;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (solve(a, b, c, d)) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
  return 0;
}
