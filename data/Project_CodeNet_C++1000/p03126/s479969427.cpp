/**
*    created: 23.05.2020 02:43:28
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
    vector<int> ch(m);
    rep(i,n) {
        int k;
        cin >> k;
        rep(j,k) {
            int a;
            cin >> a;
            ch[a-1]++;
        }
    }
    int cnt = 0;
    rep(i,m) {
        if (ch[i] == n) cnt++;
    }
    cout << cnt << endl;
    return 0;
}