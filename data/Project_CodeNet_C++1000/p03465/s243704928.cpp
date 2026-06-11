#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
int main()
{
	int n,i,j,x;
	scanf("%d",&n);
	vi a;
	int sum = 0;
	for(i=0;i<n;++i)
	{
		scanf("%d",&x);
		a.push_back(x);
		sum += x;
	}
	int m = 100000;
	bool dp[n][m];
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			dp[i][j] = false;
		}
	}
	dp[0][a[0]] = true;
	for(i=0;i<n-1;++i)
	{
		for(j=0;j<m;++j)
		{
			if(dp[i][j]==true)
			{
				if(j<=a[i+1])
				{
					dp[i+1][a[i+1]-j] = true;
				}
				else 
				{
					dp[i+1][j-a[i+1]] = true;
				}
				if(j+a[i+1]<m)
				{
					dp[i+1][j+a[i+1]] = true;
				}
			}
		}
	}
	for(i=0;i<m;++i)
	{
		if(dp[n-1][i]==true)
		{
			printf("%d",(sum+i)/2);
			return 0;
		}
	}
}
