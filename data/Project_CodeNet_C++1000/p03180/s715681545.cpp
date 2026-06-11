#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1<<16+3;
ll dp[N],add[20][20];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>add[i][j];
	for(int i=1;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				dp[i]=dp[i-(1<<j)];
				for(int k=0;k<n;k++)
				{
					if((i>>k)&1)
					{
						dp[i]+=add[k+1][j+1];
					}
				}
				break;
			}
		}
	}
	for(int i=0;i<(1<<n);i++)
	{
//		cout<<i<<":";
		for(int j=i;j!=0;j=(j-1)&i)
		{
			dp[i]=max(dp[i],dp[j]+dp[i^j]);
//			cout<<j<<' ';
		}
//		cout<<"\n";
		
	}
	cout<<dp[(1<<n)-1];
	return 0;
}