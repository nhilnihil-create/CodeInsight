#include<bits/stdc++.h>
using namespace std;
#define ll long long 



double dp[301][301][301];


double solve(ll x,ll y,ll z,ll n)
{
    if(x<0 || y<0 || z<0)
    {
        return(0.0);
    }
    if(x==0 && y==0 && z==0)
    {
        return(0.0);
    }
    if(dp[x][y][z]>=-0.1)
    {
        return(dp[x][y][z]);
    }
    double ans=(n+x*(solve(x-1,y,z,n))+y*solve(x+1,y-1,z,n)+z*(solve(x,y+1,z-1,n)))/(x+y+z);
    return(dp[x][y][z]=ans);
}

// dp(x,y,z)=1+p0*(dp(x,y,x))+p1*(dp(x-1,y,z))+p2(dp(x+1,y-1,z))+p3(dp(x,y+1,z-1))
//po=(n-(x+y+z))/n p1=x/(n) p2=y/n p3=z/n\


//dp(x,y,z)=(n+x(dp)+y(dp)+z(dp))/(x+y+z)
int main()
{
    ll n,i;
    cin>>n;
    ll a[n];
    ll x=0;
    ll y=0;
    ll z=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            x++;
        }
        else if(a[i]==2)
        {
            y++;
        }
        else if(a[i]==3)
        {
            z++;
        }
    }
    ll j,k;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            for(k=0;k<=n;k++)
            {
                dp[i][j][k]=-1.0;
            }
        }
    }
    cout<<fixed<<setprecision(10);
    cout<<solve(x,y,z,n);
}