
// Problem : T - Permutation
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_t
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
#define N 3005

//Solution

int n;
string s;
int dp[N][N];
int pre[N],suf[N];

void solve(){
    cin>>n>>s;
    dp[1][1] = 1;
    pre[1] = 1;
    suf[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-2] == '<') (dp[i][j] += pre[j-1]) %= mod;
            else (dp[i][j] += suf[j]) %= mod;
        }
        pre[1] = dp[i][1];
        for(int j=2;j<=i;j++) pre[j] = (pre[j-1]+dp[i][j])%mod;
        suf[i] = dp[i][i];
        for(int j=i-1;j>=1;j--) suf[j] = (suf[j+1]+dp[i][j])%mod;
    }
    int ans = 0;
    for(int i=1;i<=n;i++) (ans += dp[n][i]) %= mod;
    cout<<ans;
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