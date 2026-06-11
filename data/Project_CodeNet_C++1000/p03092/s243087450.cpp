#include<bits/stdc++.h>
const int N=5005;
using namespace std;
typedef long long ll;
const ll inf=1e18;
int n,a,b,p[N],x;
ll f[N],g[N],ans=inf;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<n;i++)
	scanf("%d",&x),p[x-1]=i;
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++)
		g[j]=f[j],f[j]=inf;
		for(int j=0;j<=n;j++)
		if(p[i]<j)
		f[j]=min(f[j],g[j]+a);
		else{
			if(p[i]>j)f[j]=min(f[j],g[j]+b);
			f[p[i]+1]=min(f[p[i]+1],g[j]);
		}
	}
	for(int i=0;i<=n;i++)
	ans=min(ans,f[i]);
	printf("%lld",ans);
}