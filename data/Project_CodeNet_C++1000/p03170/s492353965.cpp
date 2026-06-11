

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


void solve(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> dp(k+1);
    for(int i=0; i<=k; i++){
        for(int j=0; j<n; j++){
            if(i >= a[j] && !dp[i-a[j]]){
                dp[i] = 1;
            }
        }
    }
    // for(int i=0; i<=k; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << (dp[k]? "First": "Second");

}

int32_t main(){

    fast_cin;
    // with_tests;
    without_tests;

    return 0;
}
