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
const int N = 2500;
const int K = 19;
int n, q;
int mod = 998244353;
int a[N][N], f[N], invf[N], used[N];
vector < pair < int, int > > v;
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
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    set < pair < pair < int, int >, int > > s;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        s.insert({{-x - y, -x}, i});
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        auto x = *s.begin();
        if (i % 2) ans = ans - x.F.S; else ans = ans + x.F.F - x.F.S;
        s.erase(x);
    }
    cout << ans;
}
