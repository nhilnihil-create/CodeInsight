#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 305
#define INF 1000000005

using namespace std;

char str[SIZE];
int dp[SIZE][SIZE];
int nxt[SIZE][SIZE];

int main()
{
	scanf("%s",&str);
	int K;
	scanf("%d",&K);
	int n=strlen(str);
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			dp[i][j]=0;
		}
	}
	int mx=1;
	for(int i=0;i<=n;i++)
	{
		for(int l=0;l<n;l++)
		{
			for(int r=l;r<n;r++)
			{
				nxt[l][r]=INF;
				if(dp[l][r]>K) dp[l][r]=INF;
			}
		}
		for(int l=0;l<n;l++)
		{
			for(int r=n-1;r>=l;r--)
			{
				if(l<r) dp[l][r-1]=min(dp[l][r-1],dp[l][r]);
				if(l+1<=r) dp[l+1][r]=min(dp[l+1][r],dp[l][r]);
			}
		}
		for(int l=0;l<n;l++)
		{
			for(int r=l;r<n;r++)
			{
				if(dp[l][r]!=INF)
				{
					if(l==r) mx=max(mx,2*i+1);
					else
					{
						mx=max(mx,2*i);
						if(str[l]==str[r])
						{
							mx=max(mx,2*i+2);
							nxt[l+1][r-1]=min(nxt[l+1][r-1],dp[l][r]);
						}
						else if(dp[l][r]<K)
						{
							mx=max(mx,2*i+2);
							nxt[l+1][r-1]=min(nxt[l+1][r-1],dp[l][r]+1);
						}
					}
				}
			}
		}
		for(int l=0;l<n;l++)
		{
			for(int r=l;r<n;r++)
			{
				dp[l][r]=nxt[l][r];
			}
		}
	}
	printf("%d\n",mx);
	return 0;
}
