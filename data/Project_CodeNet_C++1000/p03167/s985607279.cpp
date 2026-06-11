#include <bits/stdc++.h>
#define MOD  1000000007;
using namespace std;
char arr[1005][1005];
int dp[1005][1005];

long long cal_ways(int x,int y,int i,int j)
{
    if(dp[i][j]!=-1)
    return dp[i][j]% MOD;
    if(i>x||j>y|| arr[i][j]=='#')
    return dp[i][j]=0;
    if(i==x && j==y )
    return dp[i][j]=1;
    else
    {
    	dp[i][j]=cal_ways(x,y,i+1,j)+cal_ways(x,y,i,j+1);
return dp[i][j]%MOD;
    }
    }

int main()
{
    memset(dp,-1,sizeof(dp));
    int x,y;
    cin>>x>>y;
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=y;j++)
        cin>>arr[i][j];
    }
    cout<<cal_ways(x,y,1,1);
    
    return 0;
}
