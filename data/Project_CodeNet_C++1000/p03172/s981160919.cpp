#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const int N = 110,M = 1e5+100,mod = 1e9+7;
typedef long long LL;

int n,k;
LL dp[N][M];  //dp[i][j] 表示前i个小朋友一共分j颗糖的方案
int a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i = 1; i<=n; i++) cin>>a[i];
    
    dp[0][0] = 1;
    for(int i = 1; i<=n; i++){
        dp[i][0] = 1;
        for(int j = 0; j<k; j++){
            dp[i][j+1] = dp[i][j] + dp[i-1][j+1];
            if(j>=a[i]) dp[i][j+1] -= dp[i-1][j-a[i]];
            dp[i][j+1]  = (dp[i][j+1]+mod)%mod;
        }
    }
    cout<<dp[n][k];
    
    
    return 0;
}