#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    bool w = true;
    if (a < b) {
      w = false;
    } else if (d < b) {
      w = false;
    } else if (d == b) {
      if (a % b > c) {
        w = false;
      }
    } else if (b > c) {
      long long g = __gcd(b, d);
      long long x = (((c + 1) - a) % g + g) % g;
      if (x == 0) {
        x = g;
      }
      long long y = x + b - c - 2;
      if (x <= g && g <= y) {
        w = false;
      }
    }
    cout << (w ? "Yes" : "No") << endl;
  }
  return 0;
}
