#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n,a,b,ans,p[10000],f[5200][5200];

void upd(LL &x,LL y){x=min(x,y);}

int main(){
	scanf("%lld%lld%lld",&n,&a,&b);
	for (LL i=1;i<=n;++i) scanf("%lld",p+i);
	memset(f,0x3f,sizeof f); f[0][0]=0;
	for (LL i=1;i<=n;++i)
		for (LL j=0;j<=n;++j)
			if (j<=p[i]){
				upd(f[i][p[i]],f[i-1][j]);
				upd(f[i][j],f[i-1][j]+a);
			}
			else{
				upd(f[i][j],f[i-1][j]+b);
			}
	ans=0x3f3f3f3f3f3f3f3fLL;
	for (LL i=0;i<=n;++i) upd(ans,f[n][i]);
	printf("%lld\n",ans);
	
	return 0;
}
			