#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
//#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 3000000;
int mod = 1000003;
int f[N], invf[N], lg[N], d[N], a[N];
int cnt;
vector < int > g[N];
int binpow(int x, int y){
    if (y == 0) return 1;
    if (y % 2) return x * binpow(x, y - 1) % mod;
    int z = binpow(x, y / 2);
    return z * z % mod;
}
int cnk(int n, int k){
    return f[n] * invf[n - k] % mod * invf[k] % mod;
}
void dfs(int v, int p = -1){
    cnt++;
    d[v] = a[cnt];
    for (auto u: g[v]){
        if (u != p) dfs(u, v);
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int ans = 0;
    int z, x, y;
    z = x = y = 0;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        int m = s.length();
        if (s[0] == 'B' && s[m - 1] == 'A') z++; else
        if (s[0] == 'B') x++; else
        if (s[m - 1] == 'A') y++;
        for (int j = 0; j < m - 1; j++){
            if (s[j] == 'A' && s[j + 1] == 'B') ans++;
        }
    }
    if (z != 0) ans +=   (z - 1);
    if (z > 1) z = 1;
    if (z == 1){
        if (x != 0 && y != 0){
            ans += 2;
            x--;
            y--;
            ans += min(x, y);
        } else
        if (x != 0 || y != 0){
            ans++;
        }
    } else{
        ans += min(x, y);
    }
    cout << ans;
}
