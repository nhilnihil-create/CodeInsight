
// Problem : P - Independent Set
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_p
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//Macros

#define ll long long
#define db long double
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define mi map<int,int>
#define mii map<pii,int>
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mod 1000000007
#define EPS 1e-9
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define inf 1e10
#define PI acos(-1.0)
#define int long long
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 100005

//Solution

int n;
int dp[N][2];
vi g[N];

void dfs(int u, int par){
    int white = 1;
    int black = 1;
    for(int i : g[u]){
        if(i != par){
            dfs(i,u);
            (black *= dp[i][0]) %= mod;
            (white *= dp[i][0]+dp[i][1]) %= mod;
        }
    }
    dp[u][0] = white;
    dp[u][1] = black;
}

void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    cout<<(dp[1][0]+dp[1][1])%mod;
}

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tests;
    //cin>>tests;
    tests = 1;
    while(tests--){
        solve();
    }
    return 0;
}