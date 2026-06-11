#include<bits/stdc++.h>
#define llong long long
#define mkpr make_pair
#define x first
#define y second
#define iter iterator
#define riter reversed_iterator
#define y1 Lorem_ipsum_
#define tm dolor_sit_amet_
#define pii pair<int,int>
using namespace std;

inline int read()
{
	int x = 0,f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) {if(ch=='-') f = -1;}
	for(; isdigit(ch);ch=getchar()) {x = x*10+ch-48;}
	return x*f;
}

const int mxN = 1e5;
int n,en;
struct Edge {int v,nxt;} e[mxN*2+3]; int fe[mxN+3];
llong d[mxN+3]; map<llong,int> mp;
int id[mxN+3];
int sz[mxN+3];
vector<pii> way;

bool cmp(int x,int y) {return d[x]<d[y];}

void addedge(int u,int v) {en++; e[en].v = v; e[en].nxt = fe[u]; fe[u] = en;}

llong dfs(int u,int x)
{
	llong ret = x;
	for(int i=fe[u]; i; i=e[i].nxt)
	{
		int v = e[i].v;
		ret += dfs(v,x+1);
	}
	return ret;
}

int main()
{
	n = read(); for(int i=1; i<=n; i++) id[i] = i;
	for(int i=1; i<=n; i++) {scanf("%lld",&d[i]); mp[d[i]] = i;}
	sort(id+1,id+n+1,cmp);
	for(int i=1; i<=n; i++) sz[i] = 1;
	for(int i=n; i>1; i--)
	{
		int u = id[i]; d[u] -= n-2ll*sz[u];
		if(!mp.count(d[u])) {puts("-1"); return 0;}
		int v = mp[d[u]]; sz[v] += sz[u]; way.push_back(mkpr(u,v)); addedge(v,u);
	}
	if(dfs(id[1],0)!=d[id[1]]) {puts("-1"); return 0;}
	for(int i=0; i<n-1; i++) {printf("%d %d\n",way[i].x,way[i].y);}
	return 0;
}