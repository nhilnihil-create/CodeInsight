/**
*    created: 23.05.2020 12:58:10
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> l(3);
    cin >> l[0] >> l[1] >> l[2];
    sort(l.begin(), l.end());
    cout << l[0] * l[1] / 2 << endl;
    return 0;
}