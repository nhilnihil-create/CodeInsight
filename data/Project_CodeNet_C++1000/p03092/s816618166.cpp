#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5002;
int n,A,B,a[N],i,j;
ll f[N][N],ans=1e18,tmp;
inline void Min(ll &x,ll y){if(y<x)x=y;}
int main(){
	scanf("%d%d%d",&n,&A,&B);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(f,63,sizeof(f));
	f[0][0]=0;
	for (i=1;i<=n;i++)
		for (j=0;j<=n;j++){
			tmp=f[i-1][j];
			if (j<a[i]) Min(f[i][a[i]],tmp),Min(f[i][j],tmp+A);
			else Min(f[i][j],tmp+B);
		}
	for (i=1;i<=n;i++) Min(ans,f[n][i]);
	printf("%lld",ans);
}