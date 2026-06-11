#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=5e5+5;
vector<int> nei[maxn];
int dfn[maxn],low[maxn],cnt;
vector<pair<int,int> > bridges;
bool vis[maxn];
void dfs(int root,int pre)
{
    vis[root]=true;
    dfn[root]=low[root]=++cnt;
    for(int i=0;i<(int)nei[root].size();i++)
    {
        int next=nei[root][i];
        if(next==pre) continue;
        if(!vis[next])
        {
            dfs(next,root);
            low[root]=min(low[root],low[next]);
        }
        else
        {
            low[root]=min(low[root],dfn[next]);
        }
    }
    if(dfn[root]==low[root]&&dfn[root]!=1)
        bridges.push_back(make_pair(root,pre));
    return;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        nei[u].push_back(v);
        nei[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n",(int)bridges.size());
    return 0;
}
/*
7 7
1 3
2 7
3 4
4 5
4 6
5 6
6 7
 
 
3 3
1 2
1 3
2 3
 
 
6 5
1 2
2 3
3 4
4 5
5 6
 */
