/*input
5 1
1 999999997 999999998 999999999 1000000000
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MX = 2e5 + 100, oo = 1ll << 60;
int v[MX];
int check(int val, int n, int x) {
    int ans = 0, k = 0, d = 1;
    for(int i = n; i >= 1; i --) {
        k ++;
        if(d == 1) ans += v[i] * 5 + x;
        else       ans += v[i] * ((d + 1) * (d + 1) - d * d);
        if(k == val) k = 0, d ++;
    }
    return ans;
}
main () {
    int n, x; cin >> n >> x;
    for(int i = 1; i <= n; i ++) cin >> v[i];
    int l = 1, r = n;
    while(l + 3 < r) {
        int d = (r - l) / 3;
        int m1 = l + d * 1;
        int m2 = l + d * 2;
        if(check(m1, n, x) <= check(m2, n, x)) r = m2;
        else                                   l = m1;
    }
    //cout << l << ' ' << r << endl;
    cout << min({check(l, n, x), check(l + 1, n, x), check(l + 2, n, x), check(l + 3, n, x)}) + n * x;
}