#include<stdio.h>
#include<string.h>
typedef long long ll;
const ll inf=1e18;
void fmin(ll&a,ll b){
	b<a?a=b:0;
}
int p[5010];
ll f[5010],g[5010],tf[5010],tg[5010];
int main(){
	int n,a,b,i,j;
	ll t;
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<=n;i++){
		scanf("%d",&j);
		p[j]=i;
	}
	for(i=1;i<=n;i++){
		t=inf;
		for(j=1;j<=n;j++){
			fmin(t,g[j-1]);
			tf[j]=t+(p[i]<j?a:(p[i]>j?b:0));
			fmin(t,f[j]);
		}
		t=inf;
		for(j=0;j<=n;j++){
			fmin(t,g[j]);
			tg[j]=t+(p[i]<=j?a:(p[i]>j?b:0));
			fmin(t,f[j+1]);
		}
		memcpy(f,tf,sizeof(tf));
		memcpy(g,tg,sizeof(tg));
	}
	t=inf;
	for(i=1;i<=n;i++)fmin(t,f[i]);
	for(i=0;i<=n;i++)fmin(t,g[i]);
	printf("%lld",t);
}