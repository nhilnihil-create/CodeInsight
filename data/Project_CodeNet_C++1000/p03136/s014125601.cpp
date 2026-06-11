/**
*    created: 23.05.2020 03:17:00
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
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(l.rbegin(), l.rend());
    int mx = l[0];
    int sum = 0;
    rep2(i,1,n) sum += l[i];
    if (mx < sum) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}