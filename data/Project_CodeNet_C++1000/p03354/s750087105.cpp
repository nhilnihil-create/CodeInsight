#include<bits/stdc++.h>
#define LL long long
#define inf 0x3fffffffffffffff
using namespace std;

int n,m,p[100010],v[100010];
vector<int> e[100010];
set<int> id,pe;

void dfs(int x)
{
    v[x]=1;
    id.insert(x);
    pe.insert(p[x]);
    for (auto y:e[x])
        if (!v[y]) dfs(y);
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    int x,y;
    for (int i=1;i<=m;i++)
        scanf("%d%d",&x,&y),
        e[x].push_back(y),
        e[y].push_back(x);
    memset(v,0,sizeof(v));
    int ans=0;
    for (int i=1;i<=n;i++)
        if (!v[i])
        {
            id.clear();pe.clear();
            dfs(i);
            for (auto x:id)
                if (pe.find(x)!=pe.end()) ans++;
        }
    printf("%d\n",ans);
    return 0;
}