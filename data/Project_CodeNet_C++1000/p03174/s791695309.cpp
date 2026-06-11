#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> can(n,vector<int> (n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>can[i][j];
        }
    }
    vector<int> dp(1<<n);
    dp[0]=1;
    for(int mask=0;mask<(1<<n)-1;mask++)
    {
        int a=__builtin_popcount(mask);
        for(int b=0;b<n;b++)
        {
            if(can[a][b] && !(mask&(1<<b)))
            {
                int mask1=mask|(1<<b);
                dp[mask1]=(dp[mask1]%mod+dp[mask]%mod)%mod;
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
}