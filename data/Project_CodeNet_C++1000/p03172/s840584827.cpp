#include <bits/stdc++.h>
using namespace std;
long long mod=pow(10,9)+7;
#define long long int
int main() {	
	int t=1;
	//cin >> t;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (t--) {
	     int dp[101][100005];
	     int n;
	     cin>>n;
	     int k;
	     cin>>k;
	     int arr[101];
	     memset(dp,0,sizeof(dp));
	     for(int i=0;i<n;i++)
	     {
	     	cin>>arr[i];
		 }
		 for(int i=0;i<=arr[0];i++)
		 {
		 	dp[0][i]=1;
		 }
		 
		for(int i=1;i<=n;i++)
		{   
		     vector<int>pre(k+1,0);
		       pre[0]=dp[i-1][0];
		       for(int j=1;j<=k;j++)
		       {
		       	  pre[j]=(pre[j-1]%mod+dp[i-1][j]%mod)%mod;
			   }
		    	for(int j=0;j<=k;j++)
		    	{
		    		if(arr[i]>=j)
		    		{
		    			dp[i][j]=pre[j];
					}
					else
					{
						dp[i][j]=(pre[j]+mod-pre[j-arr[i]-1])%mod;
					}
				}
		} 
	      cout<<dp[n-1][k];
      }
	} 
	
	
	