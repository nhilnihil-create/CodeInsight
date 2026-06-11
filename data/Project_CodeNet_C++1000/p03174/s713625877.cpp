#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

ll dp[21][1<<21];

int main()
{
	int n;
	cin>>n;
	int a[n][n];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cin>>a[i][j];
	}
	int p = (1<<n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
		{
			dp[i][j] = 0;
			int k1 = 0, k2 = j;
			while(k2!=0)
			{
				if(k2&1)
					k1++;
				k2 = (k2>>1);
			}
			if(k1!=i+1)
				continue;

			dp[i][j] = 0;

			k2 = 1;
			int ind = 0;
			while(k2<=j)
			{
				if((k2&j) && a[i][ind])
				{
					
					if(i==0)
						dp[i][j] = 1;
					else
						dp[i][j] += dp[i-1][j^k2];
					dp[i][j] %= M;
				}
				k2 = (k2<<1);
				ind++;
			}
		}
	}
	cout<<dp[n-1][p-1];
	return 0;

}
