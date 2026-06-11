#include <bits/stdc++.h>
using namespace std;
#define Maxn 400007
int last[Maxn],pre[Maxn],other[Maxn],cnt=0;
int dis[Maxn];
bool vis[Maxn];
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
}
void dfs(int u)
{
    vis[u]=true;
    for (int q=last[u];q;q=pre[q])
    {
        int v=other[q];
        if (!vis[v])
        {
            dis[v]=dis[u]+1;
            dfs(v);
        }
    }
}
int n;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v),insert(v,u);
    }
    memset(vis,false,sizeof(vis));
    dis[1]=0;
    dfs(1);
    int id=1;
    for (int i=1;i<=n;i++)
        if (dis[i]>dis[id]) id=i;
    memset(vis,false,sizeof(vis));
    dis[id]=0;
    dfs(id);
    int ans=0;
    for (int i=1;i<=n;i++)
        ans=max(ans,dis[i]);
    if (ans%3==1) printf("Second\n"); else printf("First\n");
    return 0;
}