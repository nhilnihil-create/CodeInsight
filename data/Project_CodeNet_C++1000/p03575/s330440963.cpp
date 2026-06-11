#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 55;
const int MAXM = 500;
 
struct Edge
{
    int to,next;
}edge[MAXM];
int head[MAXN],tot;
int Dfn[MAXN],Low[MAXN];
int Index,res;
 
void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
 
void Tarjan(int u, int fa)
{
    Dfn[u] = Low[u] = ++Index;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(!Dfn[v])
        {
            Tarjan(v,u);
            Low[u] = min(Low[u],Low[v]);
            if(Low[v] > Dfn[u])
                ++res;
        }
        else if(v != fa)
            Low[u] = min(Low[u],Dfn[v]);
    }
}
 
void solve(int n)
{
    Index = res = 0;
    memset(Dfn,0,sizeof(Dfn));
    memset(Low,0,sizeof(Low));
    Tarjan(1,-1);
    printf("%d\n",res);
}
 
int main()
{
    int n,m,u,v;
    memset(head,-1,sizeof(head));
    tot = 0;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d %d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    solve(n);
    return 0;
}