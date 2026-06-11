#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const int N = 410;
typedef long long LL;

int n;
LL a[N];
LL dp[N][N];  //区间dp，dp[i][j] 表示合并区间[i,j]的最小花费

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        a[i] += a[i-1];
    }
    
    
    for(int len = 2; len<=n; len++){
        for(int i = 1; i+len-1<=n; i++){
            int l = i, r = l+len-1;
            dp[l][r] = 1e14;
            for(int k = l; k<r; k++)
                dp[l][r] = min(dp[l][r],dp[l][k]+dp[k+1][r]+a[r]-a[l-1]);
        }
    }
    cout<<dp[1][n];
    
    return 0;
}