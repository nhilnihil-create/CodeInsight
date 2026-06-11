#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  int mi = 1 << 30;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) mi = min(mi, b);
    sum += a;
  }
  cout << (mi == 1 << 30 ? 0 : sum - mi) << '\n';
  return 0;
}