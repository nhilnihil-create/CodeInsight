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
    int a[n];
    for(int i = 0; i < n; i++) {
      cin>>a[i];
    }
    int dp[n];// 0 index
    // base case
    dp[0] = 0; dp[1] = abs(a[1] - a[0]);
    // populate dp
    for(int i = 2; i < n; i++) {
      dp[i] = min(dp[i-1] + abs(a[i] - a[i-1]),
                  dp[i-2] + abs(a[i] - a[i-2]));
    }
    cout<<dp[n-1];
  }

  return 0;
}
