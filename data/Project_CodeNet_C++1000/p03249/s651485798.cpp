#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define ll long long
ll read() {
    ll s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
	    if(ch=='-') w=-1;
	    ch=getchar();
	}
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
    return s*w;
}
map<ll,int> ap;
struct node{
    ll d;
    int id;
}a[M];
bool cmp(node p1,node p2) {return p1.d>p2.d;}
struct edge{
    int u,v;
    edge(int r_u=0,int r_v=0) {u=r_u,v=r_v;}
}ans[M];
vector<int> e[M]; 
int cnt;
int n,sz[M];
ll dep[M],sum;
void dfs(int x,int fa) {
    dep[x]=dep[fa]+1,sum+=dep[x];
    for(int i=0;i<e[x].size();i++)
	{
	    int to=e[x][i];
	    dfs(to,x);
	}
}
void work() {
    int tp=0;
    for(int i=1;i<=n;i++) ap[a[i].d]=a[i].id,sz[i]=1;
    for(int i=1;i<n;i++)
	{
	    ll d_F=a[i].d-n+2*sz[a[i].id];
	    if(d_F<0||d_F>=a[i].d||ap[d_F]==0) {tp=1;break ;}
	    sz[ap[d_F]]+=sz[a[i].id];
	    ans[++cnt]=edge(ap[d_F],a[i].id);
	    e[ap[d_F]].push_back(a[i].id);
	}
    dep[0]=-1;
    dfs(a[n].id,0);
    if(sum!=a[n].d) tp=1;
    if(tp) cout<<-1<<'\n';
    else for(int i=1;i<=cnt;i++) cout<<ans[i].u<<' '<<ans[i].v<<'\n';
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++) {a[i].d=read();a[i].id=i;}
    sort(a+1,a+n+1,cmp);
    work();
    return 0;
}