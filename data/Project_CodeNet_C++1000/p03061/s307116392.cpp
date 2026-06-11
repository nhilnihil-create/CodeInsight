#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  int n;
  cin >> n;
  vector<int> a(n), l(n + 1), r(n + 1);
  for (int& x : a) cin >> x;

  rep(i, 0, n) l[i + 1] = gcd(l[i], a[i]);
  rrep(i, 1, n) r[i - 1] = gcd(r[i], a[i]);

  int ans = 0;
  rep(i, 0, n) { ans = max(ans, gcd(l[i], r[i])); }
  cout << ans << endl;

  return 0;
}