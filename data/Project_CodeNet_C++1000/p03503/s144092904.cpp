#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define int long long 

signed main() {
    int n;
    cin >> n;
    int f[100][10] = {};
    rep(i, n) {
        rep(j, 10) cin >> f[i][j];
    }
    int p[100][11] = {};
    rep(i, n) {
        rep(j, 11) cin >> p[i][j];
    }

    int ans = -1e10;
    for(int bit = 1; bit < (1 << 10); bit++) {
        int sum = 0, cnt = 0;
        rep(i, n) {
            cnt = 0;
            rep(b, 10) if((bit >> b & 1) && f[i][b]) cnt++;
            sum += p[i][cnt];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
