#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    int n;
    cin >> n;
    vector<vi> a(2, vi(n));
    rep(i, 2){
        rep(j, n){
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    /* cout << "--------" << endl; */

    rep(i, n){
        ll tmp = 0;
        rep(j, i+1){
            tmp += a[0][j];
            /* cout << a[0][j] << " "; */
        }
        repa(j, i, n){
            tmp += a[1][j];
            /* cout << a[1][j] << " "; */
        }
        /* cout << "\n"; */
        ans = max(ans, tmp);
    }
    cout << ans << endl;

}