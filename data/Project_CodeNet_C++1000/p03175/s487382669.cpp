#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define NIL 0
#define INF 1e18
#define vi vector<int> 
#define vvi vector<vector<int>> 
#define vl vector<ll>
#define vvl vector<vector<ll>> 
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define pb push_back
#define F first
#define S second
#define pp pair<int,int> 
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define rpk(i,k,n) for(int i=k;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++) 
#define RPK(i,k,n) for(int i=k;i<=n;i++) 
#define ritr(i,gr) for(auto i=gr.begin();i!=gr.end();i++)

const int M = 1e9+7;

int V, E, i, j, k, u, v, x, y, p, q, r, t, n,m;
vi *g;
ll dp[2][100050];


ll dfs_util(int u, int pv) {
    if(dp[0][u]!=-1) return (dp[0][u]+dp[1][u]+M)%M;
    ll nb =1, nw=1;
    
    for(auto v: g[u]) {
        if(v==pv) continue;
        dfs_util(v, u);
        nb = (nb*dp[1][v])%M;
        nw = (nw*(dp[0][v]+dp[1][v]+M))%M;
    }
    
    dp[0][u] = nb;
    dp[1][u] = nw;
    return (dp[0][u]+dp[1][u]+M)%M;    
}

void dfs() {
    ll res=0;
    res = dfs_util(1,1);
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    cin>>V;
    g = new vi[V+1];
    rep(i,V-1) cin>>x>>y, g[x].pb(y), g[y].pb(x);
    rep(i,2) {rep(j,V+1) dp[i][j] =-1;}
    dfs();
}