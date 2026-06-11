#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int ans = 0;
  for (int i = 0; i < n/r + 1; i++) {
    for (int j = 0; j < (n-i*r)/g + 1; j++) {
      int tmp = n;
      tmp -= i*r + j*g;
      if (tmp % b == 0) ans++;
    }
  }
  cout << ans << '\n';
}
