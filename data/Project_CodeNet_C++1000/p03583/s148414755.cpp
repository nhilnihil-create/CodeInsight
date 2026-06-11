#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
// using Graph = vector<vector<int>>;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int main() {
  double N;
  cin >> N;
  for (ll h = 1; h <= 3500; ++h) {
    for (ll n = 1; n <= 3500; ++n) {
      double tmp = (N * h * n) / (4 * h * n - N * n - N * h);
      if ((int)tmp == tmp && tmp > 0 && tmp < 3500) {
        cout << h << " " << n << " " << tmp << endl;
        return 0;
      }
    }
  }
  return 0;
}
