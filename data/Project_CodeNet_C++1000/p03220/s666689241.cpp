/**
*    created: 21.06.2020 23:43:30
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long double t, a;
    cin >> t >> a;
    long double tm = 100000000000000;
    int ans;
    rep(i,n) {
        int h;
        cin >> h;
        if (abs((t - h * 0.006)- a) < tm) {
            ans = i + 1;
            tm = abs((t - h * 0.006)- a);
        }
    }
    cout << ans << endl;
    return 0;
}