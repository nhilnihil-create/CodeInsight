#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define No {puts("-1");return 0;}
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fe(i,u) for(int i=head[u];i;i=e[i].next)
using namespace std;
typedef long long ll;
inline void open(const char *s)
{
	#ifndef ONLINE_JUDGE
	char str[20];
	sprintf(str,"in%s.txt",s);
	freopen(str,"r",stdin);
//	sprintf(str,"out%s.txt",s);
//	freopen(str,"w",stdout);
	#endif
}
inline ll rd()
{
	static ll x,f;
	x=0;f=1ll;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1ll;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10ll+ch-'0';
	return f>0?x:-x;
}
const int N=100010;
struct edge{
	int u,v,next;
	edge(int u=0,int v=0,int next=0):u(u),v(v),next(next){}
}e[N];
int n,siz[N],rt;ll d[N];
int tot=0,head[N];
struct node{
	ll x;int id;
}q[N];
map<ll,int>mp;

inline bool cmp(node a,node b){return a.x>b.x;}
inline void add(int u,int v){e[++tot]=edge(u,v,head[u]);head[u]=tot;}

void dfs1(int u,int dep)
{
	d[rt]+=dep;
	fe(i,u){int v=e[i].v;dfs1(v,dep+1);}
}
void dfs2(int u)
{
	fe(i,u){
		int v=e[i].v;
		d[v]=d[u]+ll(n-(siz[v]<<1ll));
		dfs2(v);
	}
}

int main()
{
	n=rd();fo(i,1,n)mp[q[q[i].id=i].x=rd()]=i,siz[i]=1;
	sort(q+1,q+n+1,cmp);
	fo(i,1,n-1){
		int x=q[i].id;
		ll dd=q[i].x-n+(siz[x]<<1);
		if(dd>=q[i].x)No
		if(!mp.count(dd))No
		int fa=mp[dd];
		add(fa,x);siz[fa]+=siz[x];
	}
	rt=q[n].id;
	dfs1(rt,0);
	dfs2(rt);
	fo(i,1,n)if(d[q[i].id]!=q[i].x)No
	fo(i,1,tot)printf("%d %d\n",e[i].u,e[i].v);
	return 0;
}
