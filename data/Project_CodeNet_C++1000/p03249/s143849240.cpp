#include <cstdio>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define R register
#define ll long long
const int MAXN=1e5+10;

int n;
ll D[MAXN];
int siz[MAXN];
map<ll,int> loc;
set<ll> st;

struct edge
{
	int fr,to,next;
}e[MAXN<<1];
int tot;
int head[MAXN];
int dep[MAXN];

inline void add(int x,int y)
{
	tot++;
	e[tot].fr=x;e[tot].to=y;e[tot].next=head[x];head[x]=tot;
}

inline void dfs(int x,int fx)
{
	dep[x]=dep[fx]+1;
	for(R int i=head[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(y==fx) continue;
		dfs(y,x);
	}
}

int main()
{
	scanf("%d",&n);
	for(R int i=1;i<=n;i++) 
	{
		scanf("%lld",&D[i]);
		siz[i]=1;
		loc[D[i]]=i;
		st.insert(D[i]);
	}
	int rt=0,cnt=0;
	while(st.size()&&cnt<n-1)
	{
		ll dx=*st.rbegin(),dy;
		int x,y;
		st.erase(dx);
		x=loc[dx];
		dy=dx+siz[x]*2-n;
		y=loc[dy];
		if(y==0) {printf("-1\n");return 0;}
		siz[y]+=siz[x];
		add(x,y);add(y,x);
		cnt++;
	}
	rt=loc[*st.begin()];
	dfs(rt,0);
	ll ans=0;
	for(R int i=1;i<=n;i++) ans+=dep[i];
	if(ans-n!=D[rt]) {printf("-1\n");return 0;}
	
	for(R int i=1;i<=tot;i+=2)
	{
		int x=e[i].fr,y=e[i].to;
		if(x>y) swap(x,y);
		printf("%d %d\n",x,y);
	}
	return 0;
}