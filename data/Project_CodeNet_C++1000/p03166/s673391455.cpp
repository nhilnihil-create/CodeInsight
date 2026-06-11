

#include<iostream>
#include<bits/stdc++.h>
#include<array>
using namespace std;
#define int long long
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define endl "\n"
#define with_tests int t; cin >> t; while(t--){ solve(); cout << endl; }
#define without_tests solve(); cout << endl;
#define CEIL(x, y) (ll)ceil((long double)(x)/(long double)(y))
#define epsilon 1e-9 
typedef long long ll;
const int mod = 1e9+7;
const int N = 1e5+1;

vector<int> adj[N];
int vis[N];
int dp[N];
int n, u, v;

// int dp[N][N];

int dfs(int u){

    if(vis[u] == 1){
        return dp[u];
    }
    vis[u] = 1;
    for(int v: adj[u]){
        dp[u] = max(dp[u], dfs(v)+1);
    }
    return dp[u];
}

void solve(){
    
    int m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i=1; i<=n; i++){
        if(vis[i] == 0){
            dfs(i);
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, dp[i]);
        // cout << dp[i] << " ";
    }
    // cout << endl;
    cout << ans;

}

int32_t main(){

    fast_cin;
    // with_tests;
    without_tests;

    return 0;
}
