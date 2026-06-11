#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define MAX 305
int a[MAX],x[4];
double dp[MAX][MAX][MAX];
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	    x[a[i]]++;
	}
	int u=x[1]+x[2]+x[3];
	int v=x[3]+x[2];
	for(int k=0;k<=x[3];k++)
	for(int j=0;j<=v;j++)
	for(int i=0;i<=u;i++)
	{
		if(i+j+k==0)
		continue;
		dp[k][j][i]=(double)n/(i+j+k);
		if(k>0)
		dp[k][j][i]+=dp[k-1][j+1][i]*((double)k/(i+j+k));
		if(j>0)
		dp[k][j][i]+=dp[k][j-1][i+1]*((double)j/(i+j+k));
		if(i>0)
		dp[k][j][i]+=dp[k][j][i-1]*((double)i/(i+j+k));
	}
	cout<<fixed<<setprecision(10)<<dp[x[3]][x[2]][x[1]]<<"\n";
}