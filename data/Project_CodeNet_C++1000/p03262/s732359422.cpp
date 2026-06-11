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

int main() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a;
	ll r = 0;
  for (int i = 0; i < n; i++) {
		ll v;
    cin >> v;
		r = gcd(r, abs(v - x));
  }
	cout << r << endl;
}
