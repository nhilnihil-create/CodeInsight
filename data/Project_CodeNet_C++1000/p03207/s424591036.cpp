/**
*    created: 20.06.2020 02:55:43
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    sort(p.rbegin(),p.rend());
    int sum = 0;
    rep(i,n) {
        if (i == 0) sum += p[i] / 2;
        else sum += p[i];
    }
    cout << sum << endl;
    return 0;
}