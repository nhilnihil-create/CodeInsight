#include <bits/stdc++.h>
#define nl "\n"
#define pb push_back
#define E esit(0)
#define all(v) v.begin(),v.end()
using namespace std;
using ll=long long;
const int N=1e5+5;
const int INF=1e9+7;

vector<int> g[N];
int d[N],in_degree[N];
bool used[N];

void dfs (int v) {
    used[v]=true;
    for (auto e: g[v]) {
        d[e]=max(d[e],d[v]+1);
        in_degree[e]--;
        if (in_degree[e]==0) {
            dfs(e);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        in_degree[y]++;
    }
    for (int i=1;i<=n;i++){
        if (!used[i] && in_degree[i]==0) {
            dfs(i);
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
        ans=max(ans,d[i]);
    }
    cout<<ans;
    return 0;
}