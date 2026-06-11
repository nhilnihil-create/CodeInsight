#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll d;int id;
}c[100005];
bool cmp(node x,node y){return x.d>y.d;}
int fa[100005],siz[100005],deep[100005];
ll d[100005];
vector<int>to[100005];
void dfs(int x){for(auto tar:to[x])deep[tar]=deep[x]+1,dfs(tar);}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&c[i].d),c[i].id=i,siz[i]=1;
    sort(c+1,c+n+1,cmp);
    for(int i=1;i<=n;i++)d[i]=c[n+1-i].d;
    for(int i=1;i<n;i++)
    {
        int t=lower_bound(d+1,d+n+1,c[i].d+2*siz[c[i].id]-n)-d;
        t=n+1-t;
        if(c[t].d!=c[i].d+2*siz[c[i].id]-n){puts("-1");return 0;}
        fa[c[i].id]=c[t].id,siz[c[t].id]+=siz[c[i].id];
    }
    for(int i=1;i<=n;i++)if(fa[i])to[fa[i]].push_back(i);
    dfs(c[n].id);
    ll s=0;
    for(int i=1;i<=n;i++)s+=deep[i];
    if(s!=c[n].d){puts("-1");return 0;}
    for(int i=1;i<=n;i++)if(fa[i])printf("%d %d\n",i,fa[i]);
    return 0;
}