#include <bits/stdc++.h>
using namespace std;
#define mod (int) (1e9+7)
int main() {
	// your code goes here
	int n;
	int i,j,k;
	
	cin>>n;
	int a[n][n];
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>a[i][j];
	
	int dp[1<<n];
	memset(dp,0,sizeof dp);
	dp[0]=1;
	
	
	for(i=0;i<1<<n;i++)
	{
	    k=__builtin_popcount(i);
	    for(j=0;j<n;j++)
	    {
	       // cout<<i<<" : "<<dp[i]<<" , ";
	        
	        if(!(i&(1<<j)) && a[j][k])
	        {
	            dp[i^(1<<j)]+=dp[i];
	            dp[i^(1<<j)]%=mod;
	        }
	        
	    }
	   // cout<<endl;
	}
	
	
	cout<<dp[(1<<n) -1];
	return 0;
}
