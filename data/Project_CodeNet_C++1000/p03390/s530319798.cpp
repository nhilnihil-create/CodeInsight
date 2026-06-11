#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    long long a, b;
    cin >> a >> b;
    long long ok(0), ng(2e9 + 1);
    while (ng - ok > 1) {
      long long mid = (ok + ng) >> 1;
      if ((mid * mid - (mid & 1)) / 4 < a * b) {
        ok = mid;
      }
      else ng = mid;
    }
    if (a == b) {
      cout << ok - 1 << '\n';
    } else {
      cout << ok - 2 << '\n';
    }
  }
  return 0;
}