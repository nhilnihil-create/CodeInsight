#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int32_t main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    int dp[n+2][k+2] = {0};
    for(int j=0;j<=k;j++){
        dp[1][j] = (j>a[1])?0:1;
    }

    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j==0){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if(j-1-a[i]>=0)
                    dp[i][j] -= dp[i-1][j-1-a[i]];
                dp[i][j] = (dp[i][j] + mod)%mod;
            }
        }
    }

    cout<<dp[n][k]<<endl;

	return 0;
}