#include<bits/stdc++.h>
using namespace std;
int n,m,fa[100005],vv[100005];
int find(int x){
	if(x==fa[x])return x;
	int k=find(fa[x]);
	vv[x]+=vv[fa[x]];
	fa[x]=k;
	return k;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	while(m--){
		int u,v,val;
		scanf("%d%d%d",&u,&v,&val);
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			vv[fu]=vv[v]+val-vv[u];
		}
		else{
			if(vv[u]-vv[v]!=val){
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
}