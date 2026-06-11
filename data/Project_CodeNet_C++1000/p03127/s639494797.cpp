#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main() {
  ll n;
  cin >> n;
  ll g = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    g = gcd(g, a);
  }
  cout << g << endl;
}
