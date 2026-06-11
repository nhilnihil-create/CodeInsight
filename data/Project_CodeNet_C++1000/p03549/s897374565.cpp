#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = (n - m) * 100;
  ans += 1900 * m;
  for (int i = 0; i < m; i++) {
    ans *= 2;
  }
  cout << ans << '\n';
}