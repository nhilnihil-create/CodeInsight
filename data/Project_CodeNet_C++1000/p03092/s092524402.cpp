#include<bits/stdc++.h>
using namespace std;
int n,A,B,a[5010],mn[5010],nx[5010],dep[5010];
long long f[5010][5010];
int main(){
	scanf("%d %d %d",&n,&A,&B);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n+1;++i)for(int j=1;j<=n+1;++j)f[i][j]=8e18;
	f[1][1]=0;
	for(int i=1;i<=n;++i){
		int t=0;mn[n+1]=a[n+1]=nx[n]=n+1;
		for(int j=n;j;--j)if(a[j]>=i)
			mn[j]=a[mn[j+1]]<a[j]?mn[j+1]:j,nx[j-1]=j;
		else mn[j]=mn[j+1],nx[j-1]=nx[j];
		for(int j=n;j;--j)dep[j]=dep[nx[j]]+1;
		for(int j=1;j<=n;++j)if(a[j]>=i&&f[i][j]<1e18){
			int x=mn[j];
			if(j==x)f[a[x]+1][nx[j]]=min(f[a[x]+1][nx[j]],f[i][j]);
			else f[a[x]+1][j]=min(f[a[x]+1][j],f[i][j]+B);
			f[a[mn[nx[x]]]][nx[x]]=min(f[a[mn[nx[x]]]][nx[x]],f[i][j]+1ll*A*(dep[j]-dep[x]));
		}
	}long long ans=8e18;
	for(int i=1;i<=n+1;++i)ans=min(ans,min(f[i][n+1],f[n+1][i]));
	printf("%lld",ans);
}