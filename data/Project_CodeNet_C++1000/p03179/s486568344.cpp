#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define ll long long
#define PI 3.141592653589
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define EPS 1e-7
#define f first
#define s second
using namespace std;
const ll MOD = 1e9+7;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random_int(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
ll fast_power(ll x, ll p){
    ll res = 1;
    while(p > 0){
        if(p & 1){
            res = (res * x);
        }
        p = p >> 1;
        x = (x*x);
    }
    return res;
}
ll dp[3005][3005];

int main() {
    IO;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 1 + dp[0][i - 1];
    }
    for (int i = 1; i < n; i++) {

        if (s[i - 1] == '<') {
            for (int j = 1; j <= i + 1; j++)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1])%MOD;
        } else {
            for (int j = 1; j <= i + 1; j++)
                dp[i][j] = (dp[i - 1][i] - dp[i - 1][j - 1] + dp[i][j - 1])%MOD;
        }
    }

    ll ans = (dp[n - 1][n] + MOD) %MOD;
    cout << ans;
    return 0;
}
