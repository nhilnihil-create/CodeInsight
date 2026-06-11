#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
int n,k,i,j,x,l;
long long dp0[100005];
long long dp1[100005];
int main()
{

    cin>>n>>k;
    dp1[k]=1;

    for(i=1;i<=n;i++)
    {
        cin>>x;

        for(j=0;j<=k;j++)
        {
            dp0[j]=dp1[j];
            dp1[j]=0;
        }

        for(j=0;j<=k;j++)
        {
            l=j-x;
            if(l<0)
                l=0;

            dp1[l]+=dp0[j];
            if(dp1[l]>mod)
                dp1[l]-=mod;

            dp1[j+1]-=dp0[j];
            if(dp1[j+1]<0)
                dp1[j+1]+=mod;
        }

        for(j=1;j<=k;j++)
        {
            dp1[j]+=dp1[j-1];
            if(dp1[j]>mod)
                dp1[j]-=mod;
        }

    }

    cout<<dp1[0];
    return 0;
}
