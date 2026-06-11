#include <bits/stdc++.h>
using namespace std;
long long int solve(int n,int k,int v[])
{
    long long int dp[n+1][k+1];
    long long int m=pow(10,9)+7;
    for(int i=0;i<=k;i++)
    {
        dp[1][i]=(i>v[1])?0:1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j==0)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=(m+dp[i-1][j]%m+dp[i][j-1]%m-((j-1-v[i]>=0)?dp[i-1][j-1-v[i]]%m:0))%m;
                
            }
        }
    }
    return dp[n][k];
}
int main() {
	int n,k;
	cin>>n>>k;
	int v[n+1];
	for(int i=1;i<=n;i++)
	{
	    cin>>v[i];
	}
	long long int ans=solve(n,k,v);
	cout<<ans<<endl;
	return 0;
}