#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
struct node{
	ll sum;int id;
	bool operator<(const node n)const{
		return sum>n.sum;
	}
}p[maxn];
int n,sz[maxn],fa[maxn];
int to[maxn],nxt[maxn],head[maxn],el;
ll sum[maxn],tot;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,ll dis){
	tot+=dis;
	for(int i=head[u];i;i=nxt[i]) dfs(to[i],dis+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&p[i].sum),p[i].id=i,sz[i]=1;
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++) sum[i]=p[i].sum;
	for(int i=1;i<n;i++){
		int f=lower_bound(sum+1,sum+n+1,sum[i]-n+2*sz[i],greater<ll>())-sum;
		if(sum[f]!=sum[i]-n+2*sz[i] || f==i) return puts("-1"),0;
		fa[p[i].id]=p[f].id;sz[f]+=sz[i];add(f,i);
	}
	dfs(n,0);
	if(tot!=sum[n]) return puts("-1"),0;
	for(int i=1;i<=n;i++) if(fa[i]) printf("%d %d\n",i,fa[i]);
}