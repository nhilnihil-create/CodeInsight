#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
bool check(int a, int b, int c, int d) {
  if (a < b) return false;
  if (d < b) return false;
  if (c >= b) return true;

  int g = gcd(b, d);

  int mx = b + a % g - g;
  if (mx > c) return false;
  return true;
}

signed main() {
  int T;
  cin >> T;

  while (T--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (check(a, b, c, d)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
