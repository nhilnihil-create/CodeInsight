#include <iostream>
#include <cassert>
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

bool solve2(ll a, ll b, ll c, ll d) {
  if (a < b) {
    return false;
  }
  if (b > d) {
    return false;
  }
  if (b <= c + 1) {
    return true;
  }
  if (b == d) {
    if (a - b * (a / b) < c) {
      return true;
    } else {
      return false;
    }
  }
  if (a % b > c) {
    return false;
  }
  ll t = gcd(d - b, b);
  ll s = a - t * (a / t);
  ll x = s + t * ((c + t - s) / t);
  if (x < b) {
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
    if (solve2(a, b, c, d)) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }
  return 0;
}
