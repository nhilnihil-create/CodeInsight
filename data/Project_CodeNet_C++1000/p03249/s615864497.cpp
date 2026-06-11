#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

ll read() {
	char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	ll x=ch-'0';
	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

const int N=1e5+5;

int n,fa[N],ord[N],sz[N];
ll d[N],sum;
vector<int> son[N];
map<ll,int> id;

void dfs(int x,int d) {
	sum+=d;
	for(int y:son[x]) dfs(y,d+1);
}

bool cmp(int x,int y) {return d[x]<d[y];}

int main() {
	n=read();
	fo(i,1,n) d[i]=read(),ord[i]=i,sz[i]=1;
	sort(ord+1,ord+n+1,cmp);
	fo(i,1,n) id[d[ord[i]]]=i;
	fd(i,n,2) {
		int x=ord[i];
		ll s=d[x]-n+2*sz[x];
		if (!id.count(s)) {puts("-1");return 0;}
		int y=id[s];
		if (y>=i) {puts("-1");return 0;}
		fa[x]=ord[y];sz[ord[y]]+=sz[x];
		son[ord[y]].push_back(x);
	}
	dfs(ord[1],0);
	if (sum!=d[ord[1]]) {puts("-1");return 0;}
	fo(i,1,n) if (fa[i]) printf("%d %d\n",i,fa[i]);
	return 0;
}