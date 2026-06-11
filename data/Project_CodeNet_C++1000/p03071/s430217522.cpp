/**
*    created: 14.05.2020 11:14:55
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b; cin >> a >> b;
    cout << max(max(a+a-1, b+b-1), a+b) << endl;
    return 0;
}