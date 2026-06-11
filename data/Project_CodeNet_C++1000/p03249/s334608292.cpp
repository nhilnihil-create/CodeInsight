#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,f[N],si[N];
struct node
{
    ll x;
    int id;
    bool operator<(const node&o)const
    {
        return x<o.x;
    }
}a[N];
unordered_map<ll,int>mp;
vector<pair<int,int> >v;
int tot,fa[N],head[N],nex[N<<1],to[N<<1];
void add(int u,int v){to[++tot]=v;nex[tot]=head[u];head[u]=tot;}
ll dis[N];
void dfs(int u,int p)
{
    fa[u]=p;
    for(int i=head[u];i;i=nex[i])
    {
        int v=to[i];if(v==p) continue;
        dfs(v,u);
        dis[u]+=dis[v]+si[v];
    }
}
bool dfs(int u)
{
    if(a[u].x!=dis[u]) return false;
    for(int i=head[u];i;i=nex[i])
    {
        int v=to[i];if(v==fa[u]) continue;
        dis[v]=dis[u]-si[v]+(n-si[v]);
        if(!dfs(v)) return false;
    }
    return true;
}
bool check()
{
    if(v.size()!=n-1) return false;
    for(int i=0;i<v.size();i++)
        add(v[i].first,v[i].second),add(v[i].second,v[i].first);
    dfs(1,0);
    return dfs(1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i].x),a[i].id=i;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) si[i]=1,f[i]=a[i].id,mp[a[i].x]=i;
    for(int i=n;i>1;i--)
    {
        ll t=a[i].x+si[i]-(n-si[i]);
        if(mp[t]&&mp[t]<i) v.push_back({i,mp[t]}),si[mp[t]]+=si[i];
    }
    if(si[1]!=n||!check()) {printf("-1\n");return 0;}
    else for(int i=0;i<v.size();i++)
        printf("%d %d\n",f[v[i].first],f[v[i].second]);
}
