#include<bits/stdc++.h>
using namespace std;

int n,a[5001],A,B,p[5001];
long long f[5001][5001],ans;

int main()
{
	scanf("%d%d%d",&n,&A,&B);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),p[a[i]]=i;
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++) f[i][j]=1000000000000000000ll;
	f[0][0]=0;
	for (int i=1; i<=n; i++)
		for (int j=0; j<=n; j++)
			if (j<p[i]) f[i][j]=min(f[i][j],f[i-1][j]+B),f[i][p[i]]=min(f[i][p[i]],f[i-1][j]);
			else f[i][j]=min(f[i][j],f[i-1][j]+A);
	ans=1000000000000000000ll;
	for (int i=0; i<=n; i++) ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}