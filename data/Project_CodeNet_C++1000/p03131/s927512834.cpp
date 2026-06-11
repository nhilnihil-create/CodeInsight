#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll k, a, b;
  cin >> k >> a >> b;

  // A-> Bで B-A 枚増える

  ll ans;
  if (b - a <= 2 || 1 + k <= a) {
    // 叩いて増やすだけ
    ans = 1 + k;
  } else {
    ans = a;       // まずA枚になるまで叩いて増やす
    k -= (a - 1);  // 残り回数を求める
    if (k & 1) {
      // 残りが奇数なら、ABを偶数回と叩くのを1回
      ans++;
      k--;
      ans += (b - a) * (k / 2);
    } else {
      ans += (b - a) * (k / 2);
    }
  }

  cout << ans << endl;
  return 0;
}