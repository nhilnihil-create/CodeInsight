/**
*    created: 23.06.2020 23:34:57
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

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n);
    vector<int> b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    reverse(all(a));
    if (a[0] > b[0]) {
        cout << "War" << endl;
        return 0;
    }
    else {
        for (int i = a[0]+1; i <= b[0]; i++) {
            if (x < i && i <= y) {
                cout << "No War" << endl;
                return 0;
            }
        }
    }
    cout << "War" << endl;
    return 0;
}