#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  if (n == 3) {
    cout << "2 5 63" << endl;
    return 0;
  }
  vector<int> ans;
  int sum = 0;
  for (int i = 1; i <= 30000; i++) {
    if (i % 2 == 0 || i % 3 == 0) {
      ans.push_back(i);
      sum += i;
    }
    if ((int) ans.size() == n) break;
  }
  int need = (6 - sum % 6) % 6;
  for (int i = n - 1; i >= 0 ; i--) {
    if (ans[i] + need <= 30000 && ((ans[i] + need) % 2 == 0 || (ans[i] + need) % 3 == 0)) {
      ans[i] += need;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}