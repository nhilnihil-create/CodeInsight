#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    if (a[0] != 0) {
        cout << -1 << endl;
        return 0;
    }

    rep(i, N) {
        if (i == 0) continue;
        if (a[i] != 0 && a[i] - a[i - 1] > 1) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> b(N);
    rep(i, N) b[i] = i - a[i]; // a[i]が元々どこのindexから来た数値か
    ll ans = 0;
    rep(i, N) {
        if(i == N - 1 || b[i] != b[i+1]) {
            ans += (ll)i - (ll)b[i];
        }
    }

    cout << ans << endl;
}
