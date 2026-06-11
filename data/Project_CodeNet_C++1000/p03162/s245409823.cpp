/*
Code By: Sai Harsha K
 */

#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
#ifndef ONLINE_JUDGE
  // these lines to be executed in local machine not online judge
  // get input
  freopen("input.txt", "r", stdin);
  // put output
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  // solution
  int t = 1;
  while(t--) {
    int n;
    cin>>n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++) {
      cin>>a[i]>>b[i]>>c[i];
    }
    int dp[n][3]; // 0 indexed. dp[i][j] indicates max happiness on ith day with jth element
    // base case
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    // populate dp
    for(int i = 1; i < n; i++) {
      dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
      dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
      dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
    }
    cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
  }

  return 0;
}
