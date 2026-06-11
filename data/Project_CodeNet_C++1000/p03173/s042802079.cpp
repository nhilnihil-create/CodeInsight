
// Problem : N - Slimes
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_n
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
#define inf 1e18
#define PI acos(-1.0)
#define int long long
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 402

//Solution

int n,a[N],dp[N][N],pre[N];

void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++) dp[i][j] = inf;
        dp[i][i] = 0;
    }
    pre[0] = a[0];
    for(int i=1;i<n;i++) pre[i] = pre[i-1]+a[i];
    for(int i=0;i<n-1;i++) dp[i][i+1] = a[i]+a[i+1];
    for(int l=3;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j = i+l-1;
            for(int k=i;k<j;k++) dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
            dp[i][j] += (pre[j]-(i-1 >= 0 ? pre[i-1] : 0));
        }
    }
    cout<<dp[0][n-1];
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