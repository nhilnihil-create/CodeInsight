#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int ans,n,tot,d[N],dp[N],head[N],nex[2*N],to[2*N];
void add(int u,int v)
{
    to[++tot]=v;
    nex[tot]=head[u];
    head[u]=tot;
}
void dfs(int u,int fa)
{
    if(!head[u])
    {d[u]=1;return;}
    for(int i=head[u];i;i=nex[i])
    {
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
        ans=max(ans,d[u]+d[v]+1);d[u]=max(d[u],d[v]+1);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    ans++;
    if(ans%3!=2) printf("First\n");
    else printf("Second\n");
}
