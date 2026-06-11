#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll N, x;
  cin >> N;

  for (ll i = 1; i <= 3500; ++i) {
    for (ll j = 1; j <= 3500; ++j) {
      ll child = N * i * j;
      ll parent = 4 * i * j - N * j - N * i;
      if (parent != 0 && child % parent == 0) {
        x = child / parent;
        if (x > 0 && x <= 3500) {
          printf("%d %d %d\n", x, i, j);
          return 0;
        }
      }
    }
  }
}
