/**
 *    author:  math2do
 *    created: 06.09.2020 10:57:41
**/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  } 
  vector <long long> pre(n);
  pre[0] = arr[0];
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + arr[i];
  } 
  auto sum = [&] (int i, int j) {
    long long h = pre[j];
    long long l = (i - 1 >= 0 ? pre[i - 1] : 0);
    return h - l;    
  };
  long long inf = (long long) 1e18;
  vector <vector <long long>> dp(n, vector <long long>(n, inf));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      if (i == j) {
        dp[i][j] = 0;
        continue;
      } 
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum(i, j));
      } 
    } 
  } 

  cout << dp[0][n - 1] << endl;
  return 0;
}
