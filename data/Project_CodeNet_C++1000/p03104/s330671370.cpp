#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll k) {
  k += 1;
  ll ret = 0;
  ll cnt = 0;
  for (ll i = 2; i <= 1e13; i *= 2, cnt++) {
    ll g = k / i;
    ll lft = k - g * i;
    ll sum = g * (i / 2) + max(0LL, lft - i / 2);
    ret |= (1LL << cnt) * (sum & 1);
  }
  return ret;
}

int main() {
  ll a,b;
  cin >> a >> b;
  if (a == 0) {
    cout << f(b) << endl;
  } else {
    cout << (f(a-1)^f(b)) << endl;
  }
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/
