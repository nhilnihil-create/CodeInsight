

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
const int N = 3e3+1;

// vector<int> adj[N];
// int vis[N];
// int dp[N];
// int n, u, v;

// // int dp[N][N];

// int dfs(int u){

//     if(vis[u] == 1){
//         return dp[u];
//     }
//     vis[u] = 1;
//     for(int v: adj[u]){
//         dp[u] = max(dp[u], dfs(v)+1);
//     }
//     return dp[u];
// }

char a[N][N];
double dp[N][N];
double p[N];
void solve(){
    
    int n;
    cin >> n;
    // vector<double> p(n+1);
    for(int i=1; i<=n; i++){
        cin >> p[i];
        // cout 
    }
    dp[1][1] = p[1];
    dp[1][0] = 1.0-p[1];
    for(int i=2; i<=n; i++){
        dp[i][0] = dp[i-1][0]*(1.0-p[i]);
        for(int j=1; j<=i; j++){
            dp[i][j] = dp[i-1][j]*(1.0-p[i]) + dp[i-1][j-1]*p[i];
        }
    }
    double ans = 0.0;
    for(int i=(n+1)/2; i<=n; i++){
        ans += dp[n][i];
        // cout << i << " " << dp[n][i] << endl;
    }
    cout << fixed << setprecision(12) << ans;
}

int32_t main(){

    fast_cin;
    // with_tests;
    without_tests;

    return 0;
}
