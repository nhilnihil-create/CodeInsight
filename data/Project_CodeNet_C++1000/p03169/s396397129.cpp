
// Problem : J - Sushi
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_j
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
#define N 305

//Solution

db dp[N][N][N];

void solve(){
    int n;
    cin>>n;
    vi cnt(4);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        cnt[x]++; 
    }
    db p = 1.0/n;
    for(int k=0;k<=n;k++){
        for(int j=0;j<=n;j++){
            for(int i=0;i<=n;i++){
                int waste = n-i-j-k;
                if(waste == n) continue;
                if(waste < 0) break;
                db p_good = 1.0-waste*p;
                if(i) dp[i][j][k] += dp[i-1][j][k]*i*p;
                if(j) dp[i][j][k] += dp[i+1][j-1][k]*j*p;
                if(k) dp[i][j][k] += dp[i][j+1][k-1]*k*p;
                dp[i][j][k] += 1;
                dp[i][j][k] /= p_good;
            }
        }
    }
    cout<<fixed<<setprecision(12)<<dp[cnt[1]][cnt[2]][cnt[3]];
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