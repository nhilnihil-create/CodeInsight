/**
 *    author:  math2do
 *    created: 05.09.2020 12:34:24
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  } 
  vector <bool> dp(k + 1, false);
  dp[0] = false;
  // dp[i] = true if i remaining stones are present
  for (int s = 0; s <= k; s++) {
    for (int i = 0; i < n; i++) {
      if (arr[i] <= s && dp[s - arr[i]] == false) {
        dp[s] = true;
      } 
    } 
  }

  puts(dp[k] ? "First" : "Second");
  return 0;
}
