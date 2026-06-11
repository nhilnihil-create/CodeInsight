#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,rt,tot,d[N],head[N],nex[2*N],to[2*N];
void add(int u,int v)
{
    to[++tot]=v;
    nex[tot]=head[u];
    head[u]=tot;
}
void dfs(int u,int fa)
{
    d[u]=d[fa]+1;
    if(d[u]>d[rt]) rt=u;
    for(int i=head[u];i;i=nex[i])
    {
        int v=to[i];
        if(v==fa) continue;
        dfs(v,u);
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
    d[rt]=0;
    dfs(rt,0);
    if(d[rt]%3!=2) printf("First\n");
    else printf("Second\n");
}
