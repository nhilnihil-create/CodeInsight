/**
*    created: 15.06.2020 11:38:44
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
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    vector<int> now(n);
    int cnt = 0;

    auto check = [&](vector<int> vec) {
        bool ok = true;
        rep(i, vec.size()) {
            if (vec[i] != h[i]) {
                ok = false;
                break;
            }
        }
        return ok;
    };
    
    while (true) {
        if (check(now)) break;
        int t = 0;
        vector<int> c(n+1);
        rep(i,n) {
            if (now[i] < h[i]) {
                now[i]++;
                c[i]++;
            }
        }
        rep(i,n) {
            if (c[i] == 1 && c[i+1] == 0) cnt++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}