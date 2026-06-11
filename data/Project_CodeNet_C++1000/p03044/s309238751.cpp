#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define ld long double
#define vi vector<vector<ll> >
using namespace std;
const int MOD=1000000007;
const int MOD2=15000007;
const ll MAX=9187201950435737471;
const int N=100005;
const int INF=1e17;
const long double PI=acos(-1);

vector<pair<int,int> >v[N];
int x[N];
bool vis[N];

void dfs(int node,int par,int dis){
    vis[node]=1;
    int y=node;
    if(dis%2==0){
        x[y]=x[par];
    }
    else {
        x[y]=1-x[par];
    }
    for(int i=0;i<v[y].size();i++){
        if(vis[v[node][i].fi])continue;
        dfs(v[node][i].fi,node,v[y][i].se);
    }
}

void solve(int T){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].pb({b,c});
        v[b].pb({a,c});
    }
    x[0]=1;
    dfs(1,0,0);
    for(int i=1;i<=n;i++){
        cout<<x[i]<<"\n";
    }
}

int main() {
    fastio
    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
        //if(i<T)cout<<"\n";
    }
    return 0;
}



