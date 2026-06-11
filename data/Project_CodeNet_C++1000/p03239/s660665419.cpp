#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int n, t, a, b, ans = 1010;
  cin >> n >> t;
  rep(i,n)
  {
    cin >> a >> b;
    if (b <= t)
      ans = min(ans, a);
  }
  if (ans > 1000) {
    cout << "TLE";
  } else {
    cout << ans;
  }
}
