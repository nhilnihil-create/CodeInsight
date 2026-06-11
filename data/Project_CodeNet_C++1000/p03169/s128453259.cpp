#include <bits/stdc++.h>
using namespace std;
#define li long long int
#define prDouble(x) cout<<fixed<<setprecision(10)<<x;
double dp[301][301][301];
double solve(li x,li y,li z,li n)
{
    if(x==0 && y==0 && z==0)
    {
        return dp[0][0][0]=0;
    }
    if(x<0 || y<0 || z<0)
    {
        return 0;
    }
    if(dp[x][y][z]>-0.9)
    {
        return dp[x][y][z];
    }
    double ans=0;
    ans=(n*1.0+ x*1.0*solve(x-1,y,z,n)+y*1.0*solve(x+1,y-1,z,n)+z*1.0*solve(x,y+1,z-1,n))/((x+y+z)*1.0);
    return dp[x][y][z]=ans;
}

int main()
{
    li n,a,i,x=0,y=0,z=0;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        if(a==1)x++;
        if(a==2)y++;
        if(a==3)z++;
    }
    cout<<fixed<<setprecision(9)<<solve(x,y,z,n);
    return 0;
}
