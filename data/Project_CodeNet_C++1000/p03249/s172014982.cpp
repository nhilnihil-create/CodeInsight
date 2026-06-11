#include<bits/stdc++.h>
#define to edge[i].v
#define mp make_pair
#define rint register int
#define debug(x) cerr<<#x<<"="<<x<<endl
#define fgx cerr<<"-------------"<<endl
#define N 1000000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct P{int id;ll s;}a[N];
inline bool cmp(P x,P y){return x.s>y.s;}
map<ll,int> go; vector<int> e[N];
int sz[N],fa[N],n,dep[N]; ll D,gg[N];
void dfs1(int x,int la=0)
{	dep[x]=dep[la]+1; D+=dep[x];
	for(auto y:e[x]) dfs1(y,x);
}
void dfs2(int x,ll d)
{	if(d!=gg[x]){printf("-1");exit(0);}
	for(auto y:e[x]) dfs2(y,d+n-2*sz[y]);
}
int main()
{	cin>>n;
	for(rint i=1;i<=n;i++) scanf("%lld",&a[i].s),a[i].id=i,go[a[i].s]=i,gg[i]=a[i].s;
	sort(a+1,a+n+1,cmp);
	for(rint i=1;i<=n;i++) sz[i]=1;
	for(rint i=1;i<n;i++)
	{	int x=a[i].id; if(2*sz[x]-n>=0) return !printf("-1");
		ll sfa=a[i].s+2*sz[x]-n;
		if(!go[sfa]) return !printf("-1");
		fa[x]=go[sfa]; sz[fa[x]]+=sz[x];// debug(x);debug(fa[x]);
	}
	for(rint i=1;i<=n;i++) if(fa[i]) e[fa[i]].push_back(i);
	int rt=0; for(rint i=1;i<=n;i++) if(!fa[i]) rt=i;
	dep[0]=-1; dfs1(rt); dfs2(rt,D);
	for(rint i=1;i<=n;i++) if(fa[i]) printf("%d %d\n",i,fa[i]);
	return 0;
}
