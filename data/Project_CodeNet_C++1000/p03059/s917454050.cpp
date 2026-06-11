/**
*    created: 14.05.2020 10:23:53
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b, t;
    cin >> a >> b >> t;
    int num = (2 * t + 1) / (2*a);
    cout << b * num << endl;
    return 0;
}