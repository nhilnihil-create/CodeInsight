#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  if (x > y) {
    swap(x, y);
    swap(a, b);
  }

  long long ans = 0;

  if (a + b > 2 * c) {
    ans += 2 * c * x;
  }
  else ans += (a + b) * x;

  if (b > 2 * c)
    ans += 2 * c * (y - x);
  else ans += b * (y - x);

  cout << ans << endl;

  return 0;
}
