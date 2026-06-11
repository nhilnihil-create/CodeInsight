#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
#define pii pair<ll int, ll int>
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define repi(i, n) for(ll i=0; i<n; i++)
#define rep(i, a, b) for(ll i=a; i<=b; i++)
#define M 1000000007
#define INF 1e18

using namespace std;

void dfs(vector <vector<ll>> &adj, vector <vector<ll>> &dp, vector <bool> &vis, ll root){
    vis[root] = true;
    dp[root][0] = 1;
    dp[root][1] = 1;
    for(auto x: adj[root]){
        if(vis[x]) continue; 
        if(dp[x][0]<0 || dp[x][1]<0) dfs(adj, dp, vis, x);
        dp[root][0] = (dp[root][0]*dp[x][1])%M;
        dp[root][1] = (dp[root][1]*(dp[x][0]+dp[x][1])%M)%M;
    }
}

int main() {
    ios
    ll n; cin>>n;
    vector <vector<ll>> adj(n+1);
    vector <vector<ll>> dp(n+1, vector<ll>(2, -1));
    vector <bool> vis(n+1, false);
    
    repi(i, n-1){
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(adj, dp, vis, 1);
    cout<<(dp[1][0]+dp[1][1])%M;
    return 0;
}
