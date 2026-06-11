#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int fa[2*maxn];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	fa[x]=fa[y];
}
bool same(int x,int y){
	return find(x)==find(y);
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*2;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		merge(u,v+n);
		merge(v,u+n);
	}
	for(int i=1;i<=n;++i){
		if(same(i,i+n)){
			printf("%lld",1ll*n*(n-1)/2-m);
			return 0;
		}
	}
	int ls=1,rs=0;
	for(int i=2;i<=n;++i){
		if(same(i,1)) ++ls;
		else ++rs;
	}
	printf("%lld\n",1ll*ls*rs-m);
}