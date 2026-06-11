

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
const int N = 1e3+1;

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
int dp[N][N];

void solve(){
    
    int h, w;
    cin >> h >> w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> a[i][j];
        }
    }
    dp[h][w] = 1;
    for(int i=h-1; i>=1; i--){
        dp[i][w] = (a[i][w] == '#')? 0: dp[i+1][w];
    }
    for(int i=w-1; i>=1; i--){
        dp[h][i] = (a[h][i] == '#')? 0: dp[h][i+1];
    }

    for(int i=h-1; i > 0; i--){
        for(int j=w-1; j > 0; j--){
            dp[i][j] = (a[i][j] == '#')? 0: (dp[i+1][j] + dp[i][j+1])%mod;
        }
    }
    cout << dp[1][1];

}

int32_t main(){

    fast_cin;
    // with_tests;
    without_tests;

    return 0;
}
