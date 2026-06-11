#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
int main(){int h,w; cin>>h>>w; char a[h][w]; int dp[h][w]; rep(i,h)rep(j,w) cin>>a[i][j],dp[i][j]=0; dp[0][0]=1; rep(i,h)rep(j,w){if(i>0) dp[i][j]+=dp[i-1][j];if(j>0) dp[i][j]+=dp[i][j-1];dp[i][j] %= 1000000007;if(a[i][j]=='#') dp[i][j]=0;} cout<<dp[h-1][w-1];}