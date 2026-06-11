#include<bits/stdc++.h>
#define N 5200
using namespace std;
long long f[N][N];
int p[N],a[N];
int n,l,r;
int main(){	
	scanf("%d%d%d",&n,&r,&l);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)p[a[i]]=i;
	for(int i=1;i<=n;i++){
		long long now=f[i-1][0];
		for(int j=0;j<=n+1;j++){
			now=min(now,f[i-1][j]);
			if(p[i]+1>j)f[i][j]=now+l;
			else if(p[i]+1==j)f[i][j]=now;
			else f[i][j]=now+r;
		}
	}
	long long ans=1000000000000000000LL;
	for(int i=0;i<=n+1;i++)ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
}