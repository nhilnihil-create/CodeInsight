#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	int i,j;
	for(i=0;i<n;i++)
		cin>>a[i];
	ll dp[n][k+1];
	ll prefsum[k+1];
	for(i=0;i<n;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(i==0)
			{
				dp[i][j] = (j<=a[i]);
			}
			else
			{
				dp[i][j] = prefsum[j]-((j-a[i]-1>=0)?prefsum[j-a[i]-1]:0);
				dp[i][j] = (dp[i][j]+M)%M;
			}
		//	cout<<dp[i][j]<<" ";
		}
		//cout<<"\n";
		prefsum[0] = dp[i][0];
		for(int k1 = 1;k1<=k;k1++)
			prefsum[k1] = (prefsum[k1-1]+dp[i][k1])%M;
	}

	cout<<dp[n-1][k];
	return 0;

}
