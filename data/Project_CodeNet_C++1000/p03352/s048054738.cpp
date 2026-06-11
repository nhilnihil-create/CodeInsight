#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int a[2000];

signed main() {
  int x;
  cin >> x;

  a[1] = 1;
  for (int i = 2; i <= x; i++) {
    int v = i;
    while(true) {
      v *= i;
      if(v > x) break;
      a[v] = 1;
    }
  }

  int ans = 0;
  for (int i = x; i >= 0; i--) {
    if(a[i]) {
      ans = i;
      break;
    }
  }

  cout << ans << "\n";

}