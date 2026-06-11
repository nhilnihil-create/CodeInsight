#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int pl[5050],g[5050],a[5050];
long long f[5050][5050];
void mn(long long &x,long long y)
{
	x=min(x,y);
}
int main()
{
	int tmp,n,i,j,A,B;
	long long ans;
	scanf("%d%d%d",&n,&A,&B);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		pl[a[i]]=i;
		for(j=i-1;j;j--)
			if(a[j]>a[i])
				g[i]++;
	}
	for(i=1;i<=n;i++)
		for(j=0;j<=n;j++)
			f[i][j]=1e18;
	f[0][0]=0; 
	for(i=0;i<n;i++)
	{
		tmp=pl[i+1];
		for(j=0;j<=n;j++)
		{
			if(j>g[tmp])
				mn(f[i+1][j-1],f[i][j]+A);
			else
				mn(f[i+1][j],f[i][j]+B),mn(f[i+1][g[tmp]],f[i][j]);
		}
	}
	ans=1e18;
	for(i=0;i<=n;i++)
		mn(ans,f[n][i]);
	printf("%lld\n",ans);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	return 0;
}
