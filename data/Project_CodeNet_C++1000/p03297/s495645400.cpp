#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
bool solve () { 
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a < b || d < b) return false;
  if (c >= b) return true;
  long long g = __gcd(b, d);
  return c >= b + a % g - g;
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << (solve() ? "Yes\n" : "No\n");
  return 0;
}