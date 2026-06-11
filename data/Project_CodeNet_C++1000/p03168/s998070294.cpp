#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

int main()
{

	int n;
	cin>>n;
	double p[n];
	double heads[n][n+1];
	int i,j;
	for(i=0;i<n;i++)
		cin>>p[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(j>i+1)
			{
				heads[i][j] = 0;
				continue;
			}
			if(i==0)
			{
				if(j==0)
				{
					heads[i][j] = 1-p[i];
				}
				else
				{
					heads[i][j] = p[i];
				}
			}
			else
			{
				if(j==0)
				{
					heads[i][j] = (1-p[i])*heads[i-1][j];
				}
				else
				{
					heads[i][j] = (1-p[i])*heads[i-1][j]+p[i]*heads[i-1][j-1];
				}
			}
		}
	}
	double ans = 0;
	for(i=n/2+1;i<=n;i++)
		ans += heads[n-1][i];
	printf("%.10lf",ans);
	return 0;
}
