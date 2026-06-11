#include <bits/stdc++.h>
#include <numeric>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  ll h = 0, nn = 0, w = 0;
  for (ll i = 1; i <= 3500 && h == 0; ++i) {
    for (ll j = 1; j <= 3500 && h == 0; ++j) {
      ll l = n * i * j;
      ll m = 4ll * (l / n) - (l / i + l / j);
      if (m <= 0) {
        continue;
      }

      if (l % m != 0) {
        continue;
      }

      h = i;
      nn = j;
      w = l / m;
    }
  }

  cout << h << ' ' << nn << ' ' << w << '\n';
}