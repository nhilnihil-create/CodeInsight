#include <bits/stdc++.h>
#define N 100001
using namespace std;
vector <int> a[N];
int deg[N],n,m,i,u,v,p[N];
int main()
{
   // freopen("ntu.inp","r",stdin);
  //  freopen("ntu.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=n-1+m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v); deg[v]++;
    }
    queue <int> q;
    for(u=1;u<=n;u++)
        if(deg[u]==0) q.push(u);
    while(q.size()>0)
    {
        u=q.front(); q.pop();
        for(i=0;i<a[u].size();i++)
        {
            v=a[u][i];
            deg[v]--;
            if(deg[v]==0)
            {
                p[v]=u;
                q.push(v);
            }
        }
    }
    for(u=1;u<=n;u++) cout<<p[u]<<'\n';
}
