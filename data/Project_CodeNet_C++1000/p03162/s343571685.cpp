#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

int main() {
  int n,a[110000],b[110000],c[110000];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i] >> b[i] >> c[i];
  
  int dp[110000][5];
  dp[0][0] = a[0]; dp[0][1] = b[0]; dp[0][2] = c[0];
  for(int i = 1; i < n; i++) {
    dp[i][0] = max(dp[i-1][1]+a[i],dp[i-1][2]+a[i]);
    dp[i][1] = max(dp[i-1][0]+b[i],dp[i-1][2]+b[i]);
    dp[i][2] = max(dp[i-1][0]+c[i],dp[i-1][1]+c[i]);
  }
  cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) << endl;
}
