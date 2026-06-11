#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n, k, ans = 0, tmp = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    if (i % k == 0) ++tmp;
  }
  ans += tmp * tmp * tmp;
  if (k % 2 == 0) {
    tmp = 0;
    for (int i = 1; i <= n; ++i) {
      if (i % k == (k / 2)) ++tmp;
    }
    ans += tmp * tmp * tmp;
  }
  
  cout << ans << "\n";
}