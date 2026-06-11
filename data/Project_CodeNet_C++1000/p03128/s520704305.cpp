#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
  int match[] = {-1,2,5,5,4,5,6,3,7,6};
  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  for (int i = 0; i < m; i++) { cin >> a[i]; }

  vector<int> dp(n+10, -1);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] == -1) { continue; }
    for (int j = 0; j < m; j++) {
      dp[i + match[a[j]]] = max(dp[i + match[a[j]]], dp[i] + 1);
    }
  }
  string ans = "";
  sort(a.begin(), a.end(), greater<int>());
  while (n > 0) {
    for (int i = 0; i < m; i++) {
      int rem = n - match[a[i]];
      if (rem < 0) { continue; }
      if (dp[rem] == -1) { continue; }
      if (dp[rem] == dp[n] - 1) {
        ans += (char)('0' + a[i]);
        n -= match[a[i]];
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}