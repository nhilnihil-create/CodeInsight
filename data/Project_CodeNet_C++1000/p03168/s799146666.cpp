#include<bits/stdc++.h>
using namespace std;
#define ll long long 


double dp[3001][3001];

double solve(double a[],ll i,ll h,ll n)
{
    if(i>=n)
    {
        if(h>n-h)
        {
            return(1.0);
        }
        else
        {
            return(0.0);
        }
    }
    if(dp[i][h]>=0.0)
    {
        return(dp[i][h]);
    }
    double p1=1.0*a[i]*(solve(a,i+1,h+1,n));
    double p2=(1.0-a[i])*(solve(a,i+1,h,n));
    return(dp[i][h]=p1+p2);
}
int main()
{
    ll n,i,j;
    cin>>n;
    double a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            dp[i][j]=-1.0;
        }
    }
    cout<<fixed<<setprecision(10);
    cout<<solve(a,0,0,n)<<"\n";
}