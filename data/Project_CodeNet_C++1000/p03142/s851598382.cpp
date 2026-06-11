#include <bits/stdc++.h>

using namespace std;
const int N=100003;
int n,m,d[N],par[N],f[N];
vector<int> a[N];
queue<int> q;
int main()
{
   
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    m+=n-1;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        d[v]++;
    }
    int root;
    for (int i=1;i<=n;i++)
    if (d[i]==0) q.push(i);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (auto v:a[u])
        {
            if (f[v]<f[u]+1)
            {
                f[v]=f[u]+1;
                par[v]=u;
            }
            d[v]--;
            if (d[v]==0) q.push(v);
        }
    }
    for (int i=1;i<=n;i++) cout<<par[i]<<"\n";
    return 0;
}
