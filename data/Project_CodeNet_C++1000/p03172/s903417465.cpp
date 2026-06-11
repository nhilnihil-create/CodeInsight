#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	int A[n];
	for(int i=0;i<n;i++)
	{
	    cin>>A[i];
	}
	int dp[n][k+1];
	int presum[k+1];
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<=k;j++)
	    {
	        if(i==0)
	        {
	            if(j>A[i])
	            dp[i][j]=0;
	            else
	            dp[i][j]=1;
	        }
	        else if(j==0)
	        dp[i][j]=1;
	        else
	        {
	            if(j>A[i])
	            dp[i][j]=(presum[j]+M-presum[j-A[i]-1])%M;
	            else
	            dp[i][j]=presum[j];
	        }
	    }
	    presum[0]=dp[i][0];
	    for(int j=1;j<=k;j++)
	    {
	        presum[j]=(presum[j-1]%M+dp[i][j]%M)%M;
	    }
	}
	cout<<dp[n-1][k]<<endl;
	return 0;
}