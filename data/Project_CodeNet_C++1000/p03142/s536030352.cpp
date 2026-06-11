#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> A[100002];
int vs[100002],root,fa[100002];
int d[100002],need[100002];
void dfs(int u)
{
    vs[u]=1;
    for (int v:A[u])
        d[v]++;
    for (int v:A[u])
        if (d[v]==need[v]&&vs[v]==0)
        {
            dfs(v);
            fa[v]=u;
        }
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n+m-1;i++)
    {
        int a,b;cin>>a>>b;need[b]++;
        A[a].push_back(b);
    }
    for (int i=1;i<=n;i++)
        if (need[i]==0) root=i;
    dfs(root);
    for (int i=1;i<=n;i++)
        cout<<fa[i]<<'\n';
}
