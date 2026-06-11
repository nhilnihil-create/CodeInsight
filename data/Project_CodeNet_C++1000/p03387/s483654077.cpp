#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int m = max(a, max(b, c));
  int cntM1 = 0;

  // 答えは m 以上
  // m の手前まで、まず増やす。
  int ans = 0;
  while (a + 2 <= m) {
    a += 2;
    ans++;
  }
  if (a == m - 1) cntM1++;
  while (b + 2 <= m) {
    b += 2;
    ans++;
  }
  if (b == m - 1) cntM1++;
  while (c + 2 <= m) {
    c += 2;
    ans++;
  }
  if (c == m - 1) cntM1++;

  // a,b,c は m または m-1 のはず。
  // m-1 が 0 個 -> ans
  // m-1 が 1 個 -> ans+2
  // m-1 が 2 個 -> ans+1
  // m-1 が 3 個 -> ありえない。(最小がmなので)
  if (cntM1 == 1)
    ans += 2;
  else if (cntM1 == 2)
    ans++;
  cout << ans << endl;
}