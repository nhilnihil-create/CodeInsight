#include <bits/stdc++.h>
using namespace std;
using ulli = unsigned long long int;
const int MOD=1e9+7;
int main()
{
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    vector<ulli> dp(1<<n,0);
    dp[0]=1;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int j=__builtin_popcount(mask);
        for(int i=0;i<n;i++)
        {
            if(a[j][i]==1 && !(mask&(1<<i)))
            {
                dp[mask|(1<<i)]=(dp[mask|(1<<i)]+dp[mask])%MOD;
            }
        }
    }
    cout<<dp[(1<<n)-1];
}