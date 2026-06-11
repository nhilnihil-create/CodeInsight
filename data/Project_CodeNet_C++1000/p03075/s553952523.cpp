/**
*    created: 14.05.2020 13:47:38
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> d(5);
    rep(i,5) cin >> d[i];
    int k; cin >> k;
    bool ok = true;
    rep(i,5) rep(j,i) {
        if (abs(d[i]-d[j]) > k) ok = false;
    }
    if (ok) cout << "Yay!" << endl;
    else cout << ":(" << endl;
    return 0;
}