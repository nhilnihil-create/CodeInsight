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
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin>>a[i];
    }
    int dp[n];// 0 index
    memset(dp, 0x3f, sizeof(dp)); // some large number
    // base case
    dp[0] = 0;
    // populate dp
    for(int i = 1; i < n; i++) {
      for(int j = i - 1; j >= 0 && j >= i - k; j--) { // check prev k steps
        dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
      }
    }
    cout<<dp[n-1];
  }

  return 0;
}
