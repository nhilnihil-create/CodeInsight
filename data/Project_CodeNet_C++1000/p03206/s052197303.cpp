/**
*    created: 20.06.2020 02:52:25
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int d;
    cin >> d;
    if (d == 25) cout << "Christmas" << endl;
    if (d == 24) cout << "Christmas Eve" << endl;
    if (d == 23) cout << "Christmas Eve Eve" << endl;
    if (d == 22) cout << "Christmas Eve Eve Eve" << endl;
    return 0;
}