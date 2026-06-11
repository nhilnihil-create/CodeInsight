#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C; cin >> A >> B >> C;
  long long ans = 0;
  ans += min(A, C);
  C -= min(A, C);
  int tmp = min(B, C);
  ans += 2 * tmp;
  B -= tmp;
  C -= tmp;
  if (B > 0) ans += B;
  if (C > 0) ans += 1;
  cout << ans << endl;
}