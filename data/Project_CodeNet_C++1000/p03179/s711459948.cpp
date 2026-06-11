#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long,long long> ii; 	
typedef complex<long double> com;

const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector <vector<ll>> dp(n,vector<ll>(n));
    dp[0][0] = 1;
    for (int z=1;z<n;z++){
        vector <ll> pre(z);
        pre[0] = dp[z-1][0];
        for (int x=1;x<z;x++){
            pre[x] += pre[x-1]+dp[z-1][x];
            pre[x] %= mod;
        }
        for (int x=0;x<=z;x++){
            if (s[z-1] == '<'){
                if (x > 0) dp[z][x] = pre[x-1];
            } else {
                if (x > 0) dp[z][x] = pre[z-1]-pre[x-1];
                else dp[z][x] = pre[z-1];
            }
            dp[z][x] %= mod;
        }
    }
    ll ans = 0;
    for (int z=0;z<n;z++){
        ans += dp[n-1][z];
        ans %= mod;
    }
    if (ans < 0) ans += mod;
    cout << ans << endl;
}