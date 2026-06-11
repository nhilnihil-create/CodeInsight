#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N];
map<long long,int>ma;
int n,b[N],vi[N],si[N],fa[N];
bool com(int x,int y){
	return a[x]>a[y];
}
int now,v[N],nex[N],head[N];
void addedges(int x,int y){
	nex[++now]=head[x];
	head[x]=now,v[now]=y;
}
long long dfs(int x,int deep){
	long long ans=deep;
	for(int i=head[x];i;i=nex[i])
		ans+=dfs(v[i],deep+1);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ma[a[i]]=b[i]=i;
	}
	sort(b+1,b+n+1,com),vi[0]=1;
	for(int i=1;i<=n;i++)	si[i]=1;
	for(int i=1;i<n;i++){
		int k=ma[a[b[i]]-n+si[b[i]]*2];
		fa[b[i]]=k,si[k]+=si[b[i]],vi[b[i]]=1;
		if(vi[k]){
			puts("-1");
			return 0;
		}
	}
	for(int i=1;i<n;i++)
		addedges(fa[b[i]],b[i]);
	if(dfs(b[n],0)!=a[b[n]]){
		puts("-1");
		return 0;
	}
	for(int i=1;i<n;i++)
		printf("%d %d\n",b[i],fa[b[i]]);
	return 0;
}
