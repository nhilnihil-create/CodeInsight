#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  ll n;
  cin >> n;

  for (ll i = 1; i <= 3500; i++) {
    for (ll j = 1; j <= 3500; j++) {
      ll u = 4 * i * j - n * (i + j);
      ll d = n * i * j;
      if (u <= 0 || u > d) continue;
      if (d % u == 0) {
        ll k = d / u;
        printf("%ld %ld %ld\n", i, j, k);
        return 0;
      }
    }
  }
}
