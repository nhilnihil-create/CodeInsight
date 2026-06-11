#include <bits/stdc++.h>
using namespace std;

long long k, l = 2, r = 3;
vector<long long> a;

int main() {
  cin >> k;
  a.resize(k);
  for (auto &p : a) cin >> p;
  reverse(a.begin(), a.end());
  if (a[0] != 2) {
    cout << -1 << endl;
    return 0;
  }
  long long inf = (long long)1e18;
  for (int i = 0; i < k; ++i) {
    long long nl = inf, nr = -1;
    long long m = (a[i] - l % a[i]) % a[i];
    if (l + m <= r) nl = l + m;
    m = r % a[i];
    if (r - m >= l) nr = r - m;
    if (nl == inf) {
      cout << -1 << endl;
      return 0;
    }
    l = nl;
    r = nr;
    r += a[i] - 1;
  }
  cout << l << " " << r << endl;
  return 0;
}
