#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <utility>
#define FR first
#define SE second

using namespace std;

typedef long long ll;
typedef pair<ll,int> pr;

pr a[100005];
map <ll,int> mp;

int size[100005],p[100005],n;
ll num[100005];

struct Edge {
  int t,next;
  Edge() {}
  Edge(int a,int b):t(a),next(b) {}
};

Edge e[200005];
int head[100005];

ll up[100005],down[100005];
int sz[100005];

void dfs1(int x,int fa) {
  sz[x]=1;
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa) {
    	int u=e[i].t;
    	dfs1(u,x);
    	down[x]+=down[u]+sz[u];
    	sz[x]+=sz[u];
	}
}

void dfs2(int x,int fa) {
  ll s=up[x];
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa) s+=down[e[i].t]+sz[e[i].t];
  for(int i=head[x];i;i=e[i].next)
    if (e[i].t!=fa) {
    	int u=e[i].t;
    	up[u]=s-down[u]-sz[u]+n-sz[u];
    	dfs2(u,x);
	}
}

int main() {
  scanf("%d",&n);
  for(int i=1;i<=n;i++) {
  	ll x;
  	scanf("%lld",&x);
  	a[i]=pr(x,i);
  	mp[x]=i;
  	num[i]=x;
  }
  sort(a+1,a+n+1);
  for(int i=n;i>1;i--) {
  	int x=a[i].SE;
  	size[x]++;
  	if (n-2*size[x]<=0) {
  		puts("-1");
  		return 0;
	  }
	ll t=a[i].FR-(n-2*size[x]);
	if (!mp.count(t)) {
		puts("-1");
		return 0;
	}
	p[x]=mp[t];
	size[p[x]]+=size[x];
	e[2*i-1]=Edge(x,head[p[x]]);
	head[p[x]]=2*i-1;
	e[2*i]=Edge(p[x],head[x]);
	head[x]=2*i;
  }
  dfs1(1,0);
  dfs2(1,0);
  for(int i=1;i<=n;i++)
    if (up[i]+down[i]!=num[i]) {
    	puts("-1");
    	return 0;
	}
  for(int i=1;i<=n;i++)
    if (p[i]) printf("%d %d\n",p[i],i);
  return 0;
}