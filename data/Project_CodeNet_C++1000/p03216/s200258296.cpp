#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n) FOR(i,0,n)

int csum[1000005][3];
int C[1000005];

signed main() {
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    int k[q]; rep (i, q) cin >> k[i];
    rep (i, n) {
        rep (j, 3) csum[i + 1][j] = csum[i][j];
        C[i + 1] = C[i];
        if (s[i] == 'D') {
            csum[i + 1][0]++;
        }
        if (s[i] == 'M') {
            csum[i + 1][1]++;
        }
        if (s[i] == 'C') {
            csum[i + 1][2]++;
            C[i + 1] += csum[i + 1][1];
        }
    }
    rep (j, q) {
        int K = k[j] - 1;
        int ans = 0;
        rep (i, n) {
            int to = i + K;
            if (to >= n) to = n - 1;
            if (s[i] == 'D') {
                ans += C[to + 1] - C[i] - (csum[to + 1][2] - csum[i][2]) * csum[i][1];
            }
        }
        cout << ans << endl;
    }
}