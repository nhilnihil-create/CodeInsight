#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,d[N][2],tot,head[N],nex[N<<1],to[N<<1];
void add(int u,int v){to[++tot]=v;nex[tot]=head[u];head[u]=tot;}
bool vis[N];
struct edge
{
    int u,v;
}e[N];
char s[N];
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&e[i].u,&e[i].v);
        d[e[i].u][s[e[i].v]-'A']++;
        d[e[i].v][s[e[i].u]-'A']++;
        add(e[i].u,e[i].v),add(e[i].v,e[i].u);
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(!(d[i][0]&&d[i][1])) q.push(i),vis[i]=true;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i;i=nex[i])
        {
            int v=to[i];if(vis[v]) continue;
            d[v][s[u]-'A']--;
            tot--;
            if(!(d[v][0]&&d[v][1])) q.push(v),vis[v]=true;
        }
    }
    int tot=0;
    for(int i=1;i<=n;i++)
        if(!vis[i]) tot++;
    if(tot) printf("Yes\n");
    else printf("No\n");
}
