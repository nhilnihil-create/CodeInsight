#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

const int N = 1e3 + 5;
int n, x[N], y[N], cnt[2];
vector<int> d;
string ans[N];

bool in (int lim, int x, int y) { return x + y <= lim && x + y >= -lim && x - y >= -lim && x - y <= lim; }

signed main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i], cnt[ ( (x[i] + y[i]) % 2 + 2) % 2 ] ++, ans[i] = "";
    if (cnt[0] && cnt[1]) return cout << -1, 0;

    for (int i = 30; i >= 0; --i) d.pb(1 << i);

    for (int _ = 1; _ <= n; ++_) {
        if (cnt[0]) x[_] --;
        for (int i : d) {
            if (in(i - 1, x[_] - i, y[_]) ) {
                ans[_] += 'R';
                x[_] = x[_] - i;
            }
            else if (in(i - 1, x[_] + i, y[_]) ) {
                ans[_] += 'L';
                x[_] = x[_] + i;
            }
            else if (in(i - 1, x[_], y[_] - i) ) {
                ans[_] += 'U';
                y[_] = y[_] - i;
            }
            else if (in(i - 1, x[_], y[_] + i) ) {
                ans[_] += 'D';
                y[_] = y[_] + i;
            }
        }
        reverse(ans[_].begin(), ans[_].end() );
        if (cnt[0]) ans[_] += 'R';
    }

    reverse(d.begin(), d.end() );
    if (cnt[0]) d.pb(1);

    cout << d.size() << '\n';
    for (int _ : d) cout << _ << ' '; cout << '\n';
    for (int _ = 1; _ <= n; ++_) cout << ans[_] << '\n';

    return 0;
}
