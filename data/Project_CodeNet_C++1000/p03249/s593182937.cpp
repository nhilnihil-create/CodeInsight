#include <bits/stdc++.h>
const int N=100005;
int n,size[N],st[N],to[N<<1],tto[N],last[N],Next[N<<1],edge;
long long D;
struct note{
	long long dis;
	int x;
}d[N];
bool cmp(note x,note y){
	return x.dis>y.dis;
}
using std::map;
map<long long,int> m;
void add(int x,int y){
	to[++edge]=y;
	Next[edge]=last[x];
	last[x]=edge;
}
int dfs(int x,int fa,long long now){
	D+=now;
	for (int i=last[x];i;i=Next[i])
		if (to[i]!=fa)
			dfs(to[i],x,now+1);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%lld",&d[i].dis);
		d[i].x=i;
		m[d[i].dis]=i;
	}
	std::sort(d+1,d+n+1,cmp);
	for (int i=1;i<=n;i++) size[i]=1;
	for (int i=1;i<n;i++){
		long long dis=d[i].dis;
		int x=d[i].x;
		long long t=dis-abs(n-2*size[x]);
		int fa=m.find(t)->second;
		if (fa==x || !fa){
			puts("-1");
			return 0;
		}
		size[fa]+=size[x];
		st[i]=x,tto[i]=fa;
		add(x,fa),add(fa,x);
	}
	dfs(d[n].x,0,0);
	if (D!=d[n].dis){
		puts("-1");
		return 0;
	}
	for (int i=1;i<n;i++) printf("%d %d\n",st[i],tto[i]);
}