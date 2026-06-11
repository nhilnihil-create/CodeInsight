#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[200005];
int fa[200005];
int find(int x){
	if(x!=fa[x])
		return fa[x]=find(fa[x]);
	return fa[x];
}
int cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v,w;
	int cnt=0;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a[cnt].u,&a[cnt].v,&w);
		a[cnt++].w=0;
	}
	for(int i=1;i<=n;i++)
		a[cnt].u=n+1,a[cnt].v=i,a[cnt++].w=1;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(a,a+cnt,cmp);
	int ans=0;
	for(int i=0;i<cnt;i++){
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx!=fy){
			ans+=a[i].w;
			fa[fy]=fx;
		}
		else continue;
	}
	printf("%d\n",ans); 
}