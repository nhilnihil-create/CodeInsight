//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long
#define inf 20021225
#define N 100010
using namespace std;
ll read()
{
	ll s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
struct node{int id; ll d;}a[N];
bool operator<(node a,node b){return a.d<b.d;}
int sz[N],fa[N],n;
map<ll,int> f; ll d[N];
int edge[N][2]; ll val[N];
struct edge{int to,lt;}e[N]; int in[N],cnt;
void add(int x,int y){e[++cnt].to=y; e[cnt].lt=in[x]; in[x]=cnt;}
void dfs(int x)
{
	sz[x]=1; d[x]=0;
	for(int i=in[x];i;i=e[i].lt)
		dfs(e[i].to),sz[x]+=sz[e[i].to],d[x]+=d[e[i].to];
	d[x]+=sz[x]-1;
}
void getd(int x)
{
	for(int i=in[x];i;i=e[i].lt)
		d[e[i].to]=d[x]+n-sz[e[i].to]*2,getd(e[i].to);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)	a[i].id=i,a[i].d=read(),f[a[i].d]=i;
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--)
	{
		int x=a[i].id; ll w=a[i].d; sz[x]++;
		if(sz[x]>n/2)	return puts("-1"),0;
		if(w-n+sz[x]*2>=w||f.find(w-n+sz[x]*2)==f.end())	return puts("-1"),0;
		int fx=f[w-n+sz[x]*2]; sz[fx]+=sz[x]; fa[x]=fx; add(fa[x],x);
	}
	dfs(a[1].id); getd(a[1].id);
	for(int i=1;i<=n;i++)	if(a[i].d!=d[a[i].id])
		return puts("-1"),0;
	for(int i=2;i<=n;i++)
		printf("%d %d\n",fa[a[i].id],a[i].id);
	return 0;
}