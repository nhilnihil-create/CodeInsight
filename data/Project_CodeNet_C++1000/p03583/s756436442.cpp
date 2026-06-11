#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
  ll n;
  cin >> n;

  for (ll i = 1; i <= 3500; ++i) {
    for (ll j = 1; j <= 3500; ++j) {
      ll d = 4 * i * j - n * i - n * j;
      ll u = n * i * j;
      if (d != 0 && u % d == 0 && u / d > 0) {
	ll k = u / d;
	cout << i << " " << j << " " << k << '\n';
	return 0;
      }
    }
  }
  return 0;
}
