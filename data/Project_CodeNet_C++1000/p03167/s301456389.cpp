#include<bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;	
typedef long long int lli;
lli n,k,s,m,t,a,b,l,r,v,h,u,temp1,temp2,x,y,temp,q,d,mod=1e9+7,w,p,c,z;
lli grid[2000][2000],dp[2000][2000];

lli rec(lli i,lli j)
{
	if(grid[i][j]==1)
	{
		dp[i][j]=0;
	}
	
	if(i==1&&j==1)
	{
		dp[i][j]=1;
	}
	
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	
	dp[i][j]=(rec(i-1,j)%mod+rec(i,j-1)%mod)%mod;
	
	return dp[i][j];
}

int main()
{
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    char ch;
    
    for(int i=1;i<=n;i++)
    {
    	for(int j =1;j<=m;j++)
    	{
    		cin>>ch;
			
			if(ch=='.')
			{
				grid[i][j]=0;
			}	
			else
			{
				grid[i][j]=1;
			}
			
			dp[i][j]=-1;
    	}
    }
    
    rec(n,m);
    cout<<dp[n][m]<<endl;
    
}