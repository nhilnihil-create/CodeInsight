#include<bits/stdc++.h>
using namespace std;
#define int long long


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n+5][n+5];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    int x=(1<<n);
    int dp[x+10]={0};
    for(int mask=0;mask<x;mask++)
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if((mask & (1<<i)) && (mask & (1<<j)))
                    dp[mask]+=a[i][j];

    for(int mask=0;mask<x;mask++)
    {
        int submask=mask;
        while(submask)
        {
            dp[mask]=max(dp[mask],dp[submask] + dp[submask ^ mask]);
            submask=(submask-1)&mask;
        }
    }
    cout<<dp[x-1];
}
