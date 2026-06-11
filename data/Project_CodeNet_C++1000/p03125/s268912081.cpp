/**
*    created: 23.05.2020 02:40:37
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    if (b % a == 0) cout << a + b << endl;
    else cout << b - a << endl;
    return 0;
}