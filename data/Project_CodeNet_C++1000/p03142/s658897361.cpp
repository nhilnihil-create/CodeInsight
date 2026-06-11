#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
vector<pii> G[N];
int d[N],n,m,p[N];

void read()
{
    cin>>n>>m;
    for (int i=1,u,v;i<n+m;i++)
    {
        cin>>u>>v;
        G[u].pb(mp(v,1));
        d[v]++;
    }
}

void dfs(int u)
{
    for (int i=0;i<(int)G[u].size();i++)
    {
        d[G[u][i].fi]--;
        if (d[G[u][i].fi]>0) G[u][i].se=0;
    }
    for (pii v : G[u])
        if (v.se)
        {
            p[v.fi]=u;
            dfs(v.fi);
        }
}


void process()
{
    int root=1;
    for (int i=1;i<=n;i++)
        if (d[i]==0) root=i;
    dfs(root);
    for (int i=1;i<=n;i++) cout<<p[i]<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}
