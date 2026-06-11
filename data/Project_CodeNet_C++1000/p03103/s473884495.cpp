/**
*    created: 23.05.2020 00:46:59
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
    vector<pair<int,int>> mp(n);
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        mp[i] = make_pair(a,b);
    }
    sort(mp.begin(), mp.end());
    int sum = 0;
    rep(i,n) {
        if (m <= mp[i].second) {
            sum += mp[i].first * m;
            break;
        }
        else {
            sum += mp[i].first * mp[i].second;
            m -= mp[i].second;
        }
    }
    cout << sum << endl;
    return 0;
}