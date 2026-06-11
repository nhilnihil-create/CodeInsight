#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll N;
  cin >> N;
  const int limit = 3501;

  for (ll h = 1; h <= limit; h++) {
    for (ll n = 1; n <= limit; n++) {
      if (4 * h * n - N * n - N * h == 0) continue;
      if ((N * h * n) % (4 * h * n - N * n - N * h) != 0) continue;
      ll w = (N * h * n) / (4 * h * n - N * n - N * h);
      if (w <= 0) continue;
      cout << h << " " << n << " " << w << endl;
      return 0;
    }
  }
  return 0;
}
