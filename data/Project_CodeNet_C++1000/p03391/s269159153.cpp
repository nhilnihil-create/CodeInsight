#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int n; cin >> n;
  int ans = 0;
  int k = 0x7FFFFFFF, s = 0;
  bool d = false;
  for (int i = n; i--; ) {
    int a, b; cin >> a >> b;
    if (a > b) {
      k = min(b, k);
    }
    s += a;
    if (a != b) d = true;
  }
  cout << (d ? s - k : 0) << endl;
}
