#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 250000;
const int K = 19;
int n, q;
int mod = 998244353;
int  f[N], invf[N], used[N], d[N];
vector < int > g[N];
int p[N], tin[N], tout[N], t;
int binpow(int x, int y){
    if (y == 0) return 1;
    if (y % 2) return x * binpow(x, y - 1) % mod;
    int z = binpow(x, y / 2);
    return z * z % mod;
}
int c(int n, int k){
    if (k < 0) return 0;
    return f[n] * invf[k] % mod * invf[n - k] % mod;
}
void dfs(int v, int pr = -1){
    t++;
    tin[v] = t;
    tout[v] = 1e9;
    for (auto u: g[v]){
        if (u == pr) continue;
        if (p[u] == 0){
            p[u] = v;
            dfs(u, v);
        }
        else
        {
            int ver = p[u];
            if (tin[v] > tin[ver] && tin[v] < tout[ver]) p[u] = v;
        }
    }
    t++;
    tout[v] = t;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n - 1 + m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        d[v]++;
    }
    int r;
    for (int i = 1; i <= n; i++){
        if (d[i] == 0){
            r = i;
            p[i] = 0;
        }
    }
    dfs(r);
    for (int i = 1; i <= n; i++) cout << p[i] << endl;
}
