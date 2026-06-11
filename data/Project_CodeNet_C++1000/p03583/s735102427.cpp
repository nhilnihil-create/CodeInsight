#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  for (ll i = 1; i <= 3500; ++i) {
    for (ll j = 1; j <= 3500; ++j) {
      ll x = n * i * j;
      ll y = 4 * i * j - n * (i + j);
      if (y > 0 && x % y == 0) {
        printf("%lld %lld %lld\n", i, j, x / y);
        return 0;
      }
    }
  }
}