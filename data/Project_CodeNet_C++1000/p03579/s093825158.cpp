#include<bits/stdc++.h>
#define tot head[0]
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m,c[N],head[N],nex[N<<1],to[N<<1];
void add(int u,int v){to[++tot]=v;nex[tot]=head[u];head[u]=tot;}
void dfs(int u,int color)
{
    if(c[u])
    {
        if(c[u]!=color)
        {
            printf("%lld\n",(ll)n*(n-1)/2-m);
            exit(0);
        }
        return;
    }
    c[u]=color;
    for(int i=head[u];i;i=nex[i])
        dfs(to[i],c[u]^1);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
    }
    dfs(1,2);
    ll a=0,b=0;
    for(int i=1;i<=n;i++)
        if(c[i]==2) a++;
    else b++;
    ll ans=a*b*2;
    for(int i=1;i<=n;i++)
    {
        for(int j=head[i];j;j=nex[j])
            if(c[to[j]]!=c[i])
                ans--;
    }
    printf("%lld\n",ans/2);
}
