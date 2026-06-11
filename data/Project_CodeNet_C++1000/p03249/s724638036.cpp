#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define MN 100005
#define ll long long
using namespace std;
inline ll in(){
    ll x=0;bool f=0;char c;
    for (;(c=getchar())<'0'||c>'9';f=c=='-');
    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}
struct st{
	ll v;
	int id;
}a[MN];
struct edge{
	int to,nxt;
}e[MN<<1];
map <ll,int> mp;
int h[MN],fa[MN],dep[MN],siz[MN];
int n,cnt;
ll sum;
inline bool cmp(st x,st y){return x.v>y.v;}
inline void ins(int x,int y){
	e[++cnt].to=y;e[cnt].nxt=h[x];h[x]=cnt;
}
inline void dfs(int u){
	sum+=1ll*dep[u];
	for (int i=h[u];i;i=e[i].nxt){
		int v=e[i].to;
		if (v==fa[u]) continue;
		dep[v]=dep[u]+1;
		fa[v]=u;dfs(v);
	}
}
int main()
{
	n=in();
	for (int i=1;i<=n;++i){
		a[i].v=in();a[i].id=i;
		mp[a[i].v]=i;siz[i]=1;
	}sort(a+1,a+n+1,cmp);
	for (int i=1;i<n;++i){
		ll d=a[i].v-n+(siz[a[i].id]<<1);
		if (d>=a[i].v||(!mp[d])) {printf("-1");return 0;}
		ins(a[i].id,mp[d]);ins(mp[d],a[i].id);
		siz[mp[d]]+=siz[a[i].id];
	}dfs(a[n].id);
	if (sum!=a[n].v) {printf("-1");return 0;}
	for (int i=1;i<=n;++i)
	if (fa[i]) printf("%d %d\n",fa[i],i);return 0;
}