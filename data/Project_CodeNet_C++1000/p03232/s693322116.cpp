#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9 + 7;
const int N = 200005;
const int K = 50;
set < int > g[N];
int f[N], invf[N], s[N], dp[N];
int binpow(int x, int y){
    if (y == 0) return 1;
    if (y % 2) return x * binpow(x, y - 1) % mod;
    int z = binpow(x, y / 2);
    return z * z % mod;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    f[0] = 1;
    invf[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;
    for (int i = 1; i <= n; i++) invf[i] = binpow(f[i], mod - 2);
    for (int i = 1; i <= n; i++){
        s[i] = (s[i - 1] + binpow(i, mod - 2)) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ans = (ans + x * f[n] % mod * (s[i] + s[n - i + 1] - 1 + mod) % mod) % mod;
    }
    cout << ans;
}
