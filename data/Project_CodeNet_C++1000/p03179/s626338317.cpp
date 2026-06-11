#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ll long long
#define PI 3.141592653589
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define EPS 1e-7
#define PII pair<int,int>
#define s second
#define f first
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
ll MOD = 1e9+7;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random_int(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
ll fast_power(ll x, ll p){
    ll res = 1;
    while(p > 0){
        if(p & 1){
            res = (res * x)%MOD;
        }
        p = p >> 1;
        x = (x*x)%MOD;
    }
    return res;
}
void add_self(ll &a, ll b){
    a += b;
    if(a >= MOD){
        a -= MOD;
    }
}
ll rangeSum(int l, int r , ll prefix[]){
    if(l > r){
        return 0;
    }
    return (prefix[r] - ((l-1 >= 0 ) ? prefix[l-1] : 0) + MOD)%MOD;
}
int n;
string s;
int main() {
    IO;
    cin >> n;
    cin >> s;
    ll dp[n][n+1] = {};
    dp[0][1] = 1;
    ll prefix[n+1];
    for(int i = 1; i < n; i++){// numbers from 1-> i+1 where i index
        prefix[0] = dp[i-1][0];
        for(int j = 1; j < n+1; j++){
            prefix[j] = (prefix[j-1] + dp[i-1][j])%MOD;
        }
        for(int j = 1; j <= i+1; j++){
            if(s[i-1] == '>'){
                add_self(dp[i][j], rangeSum(j, i, prefix));
            }else{
                add_self(dp[i][j], rangeSum(0, j-1, prefix));
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n+1; i++){
        add_self(ans, dp[n-1][i]);
    }
    cout << ans;




    return 0;
}
