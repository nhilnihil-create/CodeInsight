#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define inf (1LL<<60)
#define prDouble(x) cout<<fixed<<setprecision(10)<<x;
#define mod 1000000000+7
#define pb push_back
li n;
li dp[402][402];

li solve(li i,li j,li *a,li *p)
{
    if(i>=j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    li k,ans=inf;
    for(k=i;k<j;k++)
    {
        ans=min(ans,p[j]-p[i]+a[i]+solve(i,k,a,p)+solve(k+1,j,a,p));
    }

    return dp[i][j]=ans;
}

int main()
{
    cin>>n;
    li a[n],p[n];
    for(li i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0)p[i]=a[i];
        else p[i]=a[i]+p[i-1];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,n-1,a,p);
    return 0;
}
