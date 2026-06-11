#include <bits/stdc++.h>

//#include <atcoder/all>

using namespace std;
// using namespace atcoder;

using ll = long long;

int main() {
  ll N;
  cin >> N;
  for (ll h = 1; h <= 3500; h++) {
    for (ll n = 1; n <= 3500; n++) {
      ll w1 = N * h * n;
      ll w2 = 4 * h * n - N * n - N * h;
      if (w2 <= 0 || w1 == 0) continue;
      if (w1 % w2 == 0) {
        cout << h << ' ' << n << ' ' << w1 / w2 << endl;
        return 0;
      }
    }
  }
}
