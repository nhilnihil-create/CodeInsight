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
const int mod = 998244353;
const int N = 650055;
const int K = 700 ;
int a[N], n, x;
int f(int s){
    int res = s * x;
    for (int i = n; i > n - s; i--){
        res += 5 * a[i];
    }
    int cnt = s;
    int val = 5;
    for (int i = n - s; i >= 1; i--){
        if (cnt == 0){
            cnt = s;
            val += 2;
        }
        res += val * a[i];
        cnt--;
    }
    return res;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1;
    int r = n;
    while(r - l > 100){
        int lo = l + (r - l) / 3;
        int hi = r - (r - l) / 3;
        if (f(lo) > f(hi)) l = lo; else r = hi;
    }
    int ans = 1e17;
    for (int i = l; i <= r; i++) ans = min(ans, f(i));
    cout << ans + x * n;
}
