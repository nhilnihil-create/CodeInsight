
// Problem : M - Candies
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_m
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

int n,k;
int dp[N];

void solve(){
    cin>>n>>k;
    dp[0] = 1;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        vi cur(k+1);
        for(int j=k;j>=0;j--){
            int l = j+1;
            int r = j+min(x,k-j);
            if(l <= r){
                (cur[l] += dp[j]) %= mod;
                if(r+1 <= k) cur[r+1] = (cur[r+1] - dp[j] + mod)%mod;
            }
        }
        int pre = 0;
        for(int i=0;i<=k;i++){
            (pre += cur[i]) %= mod;
            (dp[i] += pre) %= mod;
        }
    }
    cout<<dp[k];
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