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
vector<vector<ll>> v;
vector<ll> cost;
vector<ll> dp;
ll solve(int idx, int mask, int curmask, vector<int> &v){
    if(idx == v.size()){
        if(!curmask){
            return -INT_MAX;
        }
        return cost[curmask] + dp[curmask^mask];
    }
    return max(solve(idx+1, mask, curmask | v[idx], v), solve(idx+1, mask, curmask, v));
}
int main() {
    IO;
    int n;
    cin >> n;
    v.resize(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    cost.resize(1LL << n, 0);

    for(int i = 0; i < (1LL << n); i++){
        for(int j = 0; j < n; j++){
            if(i & 1 << j){
                for(int k = 0; k < j; k++){
                    if(i & 1 << k){
                        cost[i] += v[j][k];
                    }
                }
            }
        }
    }
    dp.resize(1 << n, 0);
    for(int i = 1; i < (1 << n); i++){
        vector<int> on;
        for(int j = 0; j < n; j++){
            if(1 << j & i){
                on.push_back(1 << j);
            }
        }
        dp[i] = solve(0, i, 0, on);
    }
    cout << dp[(1 << n)-1];



    return 0;
}
