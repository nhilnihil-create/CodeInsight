/**
*    created: 23.05.2020 01:50:10
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    double sum = 0;
    rep(i,n) {
        double x;
        string u;
        cin >> x >> u;
        if (u == "JPY") sum += x;
        else sum += x * 380000;
    }
    cout << fixed << setprecision(8);
    cout << sum << endl;
    return 0;
}