#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int X;
  cin >> X;
  ll ans = 1;
  repe(i, 1, X) {
    rep(j, 2, X) {
      ll x = pow(i, j);
      if (x > X) break;
      ans = max(ans, x);
    }
  }

  cout << ans << endl;

  return 0;
}
