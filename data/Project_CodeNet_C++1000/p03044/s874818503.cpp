#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pii make_pair
int ceil(int a, int b) { if(a%b==0) return a/b; else return a/b+1; }
vector<pair<int, int> >adj[100005];
int mp[100005];
int vis[100005], dep[100005];

void dfs(int node)
{
    //cout<<node<<endl;
    vis[node]=1;
    for(int i=0; i<adj[node].size(); i++) {
        int chl=adj[node][i].first;
        int len=adj[node][i].second;
        if(vis[chl]) continue;
        dep[chl]=dep[node]+len;
        if(dep[chl]%2==0) mp[chl]=1;
        else mp[chl]=0;
        dfs(chl);
    }
}

main()
{
    //fastio;
    int n, x, y, z;
    cin>>n;
    for(int i=0; i<n-1; i++) {
        cin>>x>>y>>z;
        adj[x].push_back(pii(y, z));
        adj[y].push_back(pii(x, z));
    }
    if(n==1) {
        cout<<"1";
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    memset(dep, 0, sizeof(dep));
    for(int i=1; i<=n; i++) {
        if(adj[i].size()==1) {
            mp[i]=1;
            dfs(i);
            break;
        }
    }
    for(int i=1; i<=n; i++) cout<<mp[i]<<endl;
}
