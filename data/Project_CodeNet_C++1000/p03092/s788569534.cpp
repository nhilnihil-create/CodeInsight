#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,A,B,a[5030];
long long f[5030][5030];
int main()
{
	scanf("%d%d%d",&n,&A,&B);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=i-1;j>=0;j--)
			{
				if(a[i]<a[j]) f[i][j]=min(f[i-1][j]+B,f[i][j]);
				else f[i][j]=min(f[i-1][j]+A,f[i][j]),f[i][i]=min(f[i][i],f[i-1][j]);
			}
	long long ans=f[0][1];
	for(int i=1;i<=n;i++) ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}	