#include <bits/stdc++.h>
using namespace std;

// dp[i][j] select i-th, last select is j
// up
// dp[i][j] = \sum_{k=1}^{j} dp[i-1][k]
// down
// dp[i][j] = \sum_{k=j+1}^{n-i+1} dp[i-1][k]


const int M=3005;
const int MO=1e9+7;

inline int add(int x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
	return x;
}
inline int sub(int x,int y)
{
	x-=y;
	if(x<0) x+=MO;
	return x;
}
inline int mul(int x,int y)
{
	return 1LL*x*y%MO;
}
inline void addv(int &x,int y)
{
	x+=y;
	if(x>=MO) x-=MO;
}
inline void subv(int &x,int y)
{
	x-=y;
	if(x<0) x+=MO;
}
inline void mulv(int &x,int y)
{
	x=1LL*x*y%MO;
}

char s[M];
int dp[M][M];
int sum[M];

int main()
{
	int n;
	scanf("%d%s",&n,s+2);
	for(int i=1;i<=n;i++)
		dp[1][i]=1;
	for(int i=2;i<=n;i++)
	{
		int m=n-i+1; // [1~m] left
		if(s[i]=='<')
		{
			for(int j=1;j<=m;j++)
				sum[j]=add(sum[j-1],dp[i-1][j]);
			for(int j=1;j<=m;j++)
				dp[i][j]=sum[j];
		}
		else // s[i]=='>'
		{
			sum[m+1]=dp[i-1][m+1];
			for(int j=m;j>=1;j--)
				sum[j]=add(sum[j+1],dp[i-1][j]);
			for(int j=1;j<=m;j++)
				dp[i][j]=sum[j+1];
		}
		// cout<<i<<" : ";
		// for(int j=1;j<=n;j++)
		// 	cout<<dp[i][j]<<" ";
		// cout<<endl;
	}
	printf("%d\n",dp[n][1]);
	return 0;
}