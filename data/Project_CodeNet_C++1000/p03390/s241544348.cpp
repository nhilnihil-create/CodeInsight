#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int q;
  cin >> q;
  auto eval = [] (long long num, long long a, long long b) {
    long long lim = a * b - 1;
    long long st = max(1LL, num / 2 - 100);
    long long en = min(num, num / 2 + 100);
    for (long long i = st; i <= en; i++) {
      long long x = i;
      long long y = num - i + 1;
      if (x == a || y == b || x == b || y == b) continue;
      if (x * y > lim) {
        //cerr << num << " " << lim << " " << x * y << endl;
        return false;
      }
    }
    //cerr << num << " " << lim << " ok" << endl;
    return true;
  };
  while (q--) {
    long long a, b;
    cin >> a >> b;
    if (a == b) {
      cout << a * 2 - 2 << '\n';
      continue;
    }
    if (a > b) swap(a, b);
    long long lo = 0, hi = a + b + 10;
    while (hi - lo > 1) {
      long long mid = (hi + lo) >> 1;
      if (eval(mid, a, b)) lo = mid;
      else hi = mid;
    }
    cout << lo - 1 - (b - a == 1) << '\n';
  }
  return 0;
}