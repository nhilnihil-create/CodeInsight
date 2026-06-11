#include<iostream>
using namespace std;
long long a[17][17];
long long gt[1<<17];
long long dp[1<<17];
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}	
	for(int S=0;S<(1<<n);S++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if((S>>i)&1 && (S>>j)&1) gt[S]+=a[i][j];
			}
		}
	}
	for(int S=1;S<(1<<n);S++)
	{
		for(int k=S;k;k=(k-1)&S)
		{
			dp[S]=max(dp[S],gt[k]+dp[S^k]);
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}