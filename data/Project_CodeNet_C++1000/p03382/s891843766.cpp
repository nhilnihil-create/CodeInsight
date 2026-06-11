#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector <int> a(n);
  int mx = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  int need = (mx + 1) / 2; int ans = 0;
  for(int i = 0; i < n; i++) {
    if(abs(need - a[i]) < abs(need - ans)) {
      ans = a[i];
    }
  }
  cout << mx << ' ' << ans << '\n';
}
