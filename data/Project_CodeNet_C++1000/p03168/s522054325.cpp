#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define M 1000000007  // 10^9+7

ld coins(ld arr[], int n, int heads, int i, vector<vector<ld>> &dp){
    if(i == n)
        return heads > n/2;
    if(dp[i][heads] != -1)
        return dp[i][heads];
    ld op1 = coins(arr, n, heads+1, i+1, dp)*arr[i];
    ld op2 = coins(arr, n, heads, i+1, dp)*(1-arr[i]);
    ld ans = op1 + op2;
    dp[i][heads] = ans;
    return ans;
}

int main()
{
 int n;
 cin>>n;
 ld arr[n];
 for(int i=0; i<n; i++)
    cin>>arr[i];
 vector<vector<ld>> dp(n, vector<ld>(n+1, -1));
 ld ans = coins(arr, n, 0, 0, dp);
 cout<<fixed<<setprecision(9)<<ans;
 return 0;
}

