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
const int N = 350000;
const int K = 19;
int n, q;
int mod =  1e9 + 7;
int s1[N], s2[N], a[N], ans[N], f[N], invf[N];
string t[N], d[N], s;
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
int check (int x){
    for (int i = 1; i <= q; i++){
        if (s[x - 1] == t[i][0]){
            if (d[i] == "L"){
                if (x == 1) return -1;
                x--;
            } else{
                if (x == n) return 1;
                x++;
            }
        }
    }
    return 0;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    cin >> s;
    for (int i = 1; i <= q; i++){
        cin >> t[i];
        cin >> d[i];
    }
    if (check(1) == -1 && check(n) == -1){
        cout << 0;
        return 0;
    }
    if (check(1) == 1 && check(n) == 1){
        cout << 0;
        return 0;
    }
    int ans = 0;
    if (check(1) != 0){
        int l = 1;
        int r = n;
        while(r - l > 1){
            int mid = (r + l) / 2;
            if (check(mid) == -1) l = mid; else r = mid;
        }
        ans += l;
    }
    if (check(n) != 0){
        int r = n;
        int l = 1;
        while(r - l > 1){
            int mid = (r + l) / 2;
            if (check(mid) == 1) r = mid; else l = mid;
        }
        ans += (n - r + 1);
    }
    cout << n - ans;
}
