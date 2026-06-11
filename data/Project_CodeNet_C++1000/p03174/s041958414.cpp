#include <bits/stdc++.h>
using namespace std;
long long int dp[22][1<<22];
long long int m=1000000007;
long long int solve(int comp[23][23],int i,long long int womensubset,int n)
{
    if(i==n+1)
    {
        if(womensubset==0)
        {
            return 1;
        }
        return 0;
        
    }
    if(dp[i][womensubset]!=-1)
    {
        return dp[i][womensubset];
    }
    long long int ans=0;
    
    for(int w=0;w<n;w++)
    {
        if((1<<w)&womensubset&&comp[i][w+1])
        {
            ans+=solve(comp,i+1,(1<<w)^womensubset,n);
            ans=ans%m;
        }
    }
    return dp[i][womensubset]=ans;
}
int main() {
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	int comp[23][23];
	for(int i=1;i<=n;i++)
	{
	    for(int j=1;j<=n;j++)
	    {
	        cin>>comp[i][j];
	    }
	}
	long long int ans=solve(comp,1,((1<<n)-1),n);
	cout<<ans<<endl;
	return 0;
}