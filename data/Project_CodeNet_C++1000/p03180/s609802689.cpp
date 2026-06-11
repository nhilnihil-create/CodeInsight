
// Problem : U - Grouping
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_u
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
int a[20][20];
int cost[1<<20];
int dp[1<<20];

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(!((mask>>i)&1)) continue; 
            for(int j=i+1;j<n;j++){
                if(!((mask>>j)&1)) continue;
                cost[mask] += a[i][j];
            }
        }
    }
    int ans = 0;
    dp[0] = 0;
    for(int mask=1;mask<(1<<n);mask++){
        dp[mask] = cost[mask];
        for(int submask=mask;submask>=0;submask=(submask-1)&mask){
            dp[mask] = max(dp[mask],dp[submask]+cost[mask^submask]);
            if(submask == 0) break;
        }
        ans = max(ans,dp[mask]);
    }
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