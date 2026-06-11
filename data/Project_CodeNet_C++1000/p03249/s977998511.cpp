#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long LL;
LL read()
{
    char c=getchar();LL f=1,sum=0;
    while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
LL n;
struct node{
	LL id,dis;
}a[maxn];
LL siz[maxn],fa[maxn],d[maxn],dep[maxn];
vector<LL> edge[maxn];
LL ans;
bool cmp(node l,node r){return l.dis<r.dis;}
void dfs(LL u,LL fa)
{
	dep[u]=dep[fa]+1;
	for(int i=0;i<edge[u].size();i++) if(edge[u][i]!=fa) dfs(edge[u][i],u);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i].dis=read(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) d[i]=a[i].dis;
	for(int i=n;i>=2;i--)
	{
		siz[a[i].id]++;
		LL tmp=d[i]-(n-2*siz[a[i].id]);
		LL pos=lower_bound(d+1,d+i,tmp)-d;
		if(pos>=i||d[pos]!=tmp) return puts("-1"),0;
		siz[a[pos].id]+=siz[a[i].id];
		fa[a[i].id]=a[pos].id;
	}
	for(int i=1;i<=n;i++)
	if(fa[i]) edge[fa[i]].push_back(i);
	dep[0]=-1;
	dfs(a[1].id,0);
	for(int i=1;i<=n;i++) ans+=dep[i];
	if(ans!=d[1]) return puts("-1"),0; 
	for(int i=1;i<=n;i++) if(fa[i]) printf("%lld %lld\n",i,fa[i]);
} 