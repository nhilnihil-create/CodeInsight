#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int D, N;
  cin >> D >> N;

  int ans;
  if (D == 0) {
    ans = N;
    if (N % 100 == 0) ans += 1;
  }
  if (D == 1) {
    ans = 100 * N;
    if (N % 100 == 0) ans += 100;
  }
  if (D == 2) {
    ans = 10000 * N;
    if (N % 100 == 0) ans += 10000;
  }

  cout << ans << endl;
  return 0;
}
