#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll x, y;
  cin >> x >> y;

  ll ans;
  if (x % y == 0) {
    // xの倍数はすべてyの倍数となってしまう。
    ans = -1;
  } else {
    ans = x;
  }

  cout << ans << endl;
  return 0;
}
