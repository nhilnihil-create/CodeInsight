#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ll k, a, b;
  cin >> k >> a >> b;

  ll ans = 1;

  if (b - a <= 2) {
    cout << 1 + k << endl;
    return 0;
  }
  if (k <= a - 1) {
    cout << 1 + k << endl;
    return 0;
  }

  ans = a;
  ll num = k - (a - 1);
  if (num % 2 == 0) {
    ans += num / 2 * (b - a);
  } else {
    ans += num / 2 * (b - a) + 1;
  }

  cout << ans << endl;
}
