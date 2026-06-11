#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
int n,i,j,mask,nr,b;
int a[25][25];
long long dp[3000005];
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];

    dp[0]=1;
    for(mask=1;mask<(1<<n);mask++)
    {
        nr=__builtin_popcount(mask)-1;
        for(b=0;b<n;b++)
        {
            if(((mask>>b)&1) && a[nr][b])
            {
                dp[mask]+=dp[mask-(1<<b)];
                if(dp[mask]>mod)
                    dp[mask]-=mod;
            }

        }
    }

    cout<<dp[(1<<n)-1];
    return 0;
}
