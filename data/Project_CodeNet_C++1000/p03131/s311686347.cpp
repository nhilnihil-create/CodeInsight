#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  ll k, a, b;
  cin >> k >> a >> b;

  // たたき続けた方が良い場合
  if (b-a <= 2) {
    cout << 1+k << endl;
    return 0;
  }

  // 交換までたどり着けない場合
  if (k <= a) {
    cout << 1+k << endl;
    return 0;
  }

  ll ans = 0;
  ans = a;
  ans += max(0,(int)((k-(a-1))/2))*(b-a);
  if ((k-(a-1)) % 2 != 0) ans += 1;
  cout << ans << endl;
}
