#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int r, D, x2000;
  cin >> r >> D >> x2000;

  int x = x2000;
  rep(i, 0, 10) {
    x = r * x - D;
    cout << x << endl;
  }

  return 0;
}
