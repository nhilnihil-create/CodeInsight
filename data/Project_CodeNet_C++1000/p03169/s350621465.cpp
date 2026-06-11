#include <bits/stdc++.h>
#include<string.h>
using namespace std;
#define li long long int
#define mod 1000000000+7
li n;

double dp[305][305][305];

double f(li x,li y,li z)
{
    if(x==0 && y==0 && z==0)
        return 0;

    if(x<0 || y<0 || z<0)
    {
        return 0;
    }
    if(dp[x][y][z]>-0.9)
    {
        return dp[x][y][z];
    }
    double exp=(n + x*f(x-1,y,z)+ y*f(x+1,y-1,z) + z*f(x,y+1,z-1));
    return dp[x][y][z]=exp/(x+y+z);
}
int main()
{
    cin>>n;
    li t;
    li x1=0,y1=0,z1=0;
    memset(dp,-1.0,sizeof(dp));
    li i;
    for(i=1;i<=n;i++)
    {
        cin>>t;
        if(t==1)x1++;
        if(t==2)y1++;
        if(t==3)z1++;
    }
    cout<<fixed<<setprecision(10)<<f(x1,y1,z1);
    return 0;
}
