#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	ll pref[n+1] = {0};
	int i,j;
	pref[0] = 0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		pref[i+1] = pref[i]+a[i];
	}
	ll dp[n][n]={0};
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			int k = j+i;
			if(j==k)
			{
				dp[j][k] = 0;
			}
			else
			{	
				int l = j;
				dp[j][k] = dp[j][l]+dp[l+1][k]+pref[k+1]-pref[j];
				for(l = j+1;l<k;l++)
				{
					dp[j][k] = min(dp[j][k],dp[j][l]+dp[l+1][k]+pref[k+1]-pref[j]);
				}
			}
		}
	}

	// for(i=0;i<n;i++)
	// {
	// 	for(j=0;j<n;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<"\n";
	// }

	cout<<dp[0][n-1];
	return 0;
}
