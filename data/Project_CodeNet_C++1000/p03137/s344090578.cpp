/**
*    created: 23.05.2020 12:32:12
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    if (m <= n) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> x(m);
    rep(i,m) cin >> x[i];
    sort(x.begin(), x.end());
    int range = x[m-1] - x[0];
    vector<int> dif(m-1);
    rep(i,m-1) dif[i] = x[i+1] - x[i];
    sort(dif.rbegin(), dif.rend());
    int sum = range;
    rep(i,n-1) sum -= dif[i];
    cout << sum << endl;
    return 0;
}