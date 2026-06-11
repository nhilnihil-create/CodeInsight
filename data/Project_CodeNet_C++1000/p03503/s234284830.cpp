#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    bool f[n][10];
    int p[n][11];
    rep(i,n) rep(j,10) cin >> f[i][j];
    rep(i,n) rep(j,11) cin >> p[i][j];
        
    int64_t ans = -100100100100;
    for (int bit = 1; bit < (1<<10); bit++) {
        int64_t benefit = 0;
        rep(shop, n) {
            int cnt = 0;
            rep(i,10) {
                if (bit & (1 << i) && f[shop][i]) cnt++;
            }
        benefit += p[shop][cnt];
        }
        ans = max(ans, benefit);
    }
    cout << ans << endl;
}
