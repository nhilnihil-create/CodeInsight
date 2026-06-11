#include<bits/stdc++.h>
using namespace std;
#define llong long long
#define pii pair<llong,int>
#define fi first
#define se second

int n;
pii a[1000100];
llong d[1000100];
int siz[1000100];
llong cd;

struct data{
	int to,nxt;
}mp[2000200];
int head[1000100],cnt;
void link(int x,int y)
{
	mp[++cnt].to=y;
	mp[cnt].nxt=head[x];
	head[x]=cnt;
}
struct UFS{
	int fa[1000100];
	void reset(){for(int i=1;i<=n;++i)fa[i]=i;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	bool merge(int x,int y)
	{
		int fx=find(x),fy=find(y);
		if(fx==fy)return 1;
		fa[fx]=fy;
		return 0;
	}
}ufs;
int ed[1000100][2];
void dfs(int x,int fa,int nd)
{
	cd+=nd;
	for(int i=head[x];i;i=mp[i].nxt)
		if(mp[i].to!=fa)
			dfs(mp[i].to,x,nd+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i].fi),a[i].se=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)d[i]=a[i].fi,siz[i]=1;
	ufs.reset();
	for(int i=n;i>1;--i)
	{
//		cout<<endl;
//		cout<<"i: "<<i<<endl;
		int np=a[i].se;
		llong nd=d[i]+siz[np]-(n-siz[np]);
		int p=lower_bound(d+1,d+n+1,nd)-d;
		if(d[p]!=nd)puts("-1"),exit(0);
		p=a[p].se;
//		cout<<"np: "<<np<<" siz: "<<siz[np]<<" d: "<<d[i]<<" nd: "<<nd<<" p: "<<p<<endl;
		link(p,np);link(np,p);
		ed[i-1][0]=p,ed[i-1][1]=np;
		siz[p]+=siz[np];
		if(ufs.merge(np,p))puts("-1"),exit(0);
	}
	dfs(a[1].se,0,0);
	if(cd!=d[1])puts("-1"),exit(0);
	for(int i=1;i<n;++i)printf("%d %d\n",ed[i][0],ed[i][1]);
	return 0;
}
