#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, h;
  cin >> n >> h;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int a_mx = *max_element(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<>());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] < a_mx) {
      break;
    }
    h -= b[i];
    ans++;
    if (h <= 0) {
      cout << ans << endl;
      return 0;
    }
  }
  cout << ans + (h + a_mx - 1) / a_mx << endl;
}
