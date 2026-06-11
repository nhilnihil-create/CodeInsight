#include <bits/stdc++.h>
using namespace std;

using LL = long long;
LL a, b;

signed main() {
  // freopen("in", "r", stdin);
  while(cin >> a >> b) {
    if(a + b == 15) printf("+\n");
    else if(a * b == 15) printf("*\n");
    else printf("x\n");
  }
  return 0;
}
