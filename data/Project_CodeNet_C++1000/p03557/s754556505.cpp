#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    ll ans = 0;
    cin >> n;
    vector<vector<ll>> a(3, vector<ll>(n));
    rep(i, 3) {
        rep(j, n) {
            cin >> a[i][j];
        }
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    sort(a[2].begin(), a[2].end());
    rep(i, n) {
        auto und = lower_bound(a[0].begin(), a[0].end(), a[1][i]) - 1;
        auto hed = upper_bound(a[2].begin(), a[2].end(), a[1][i]);
        ans += (und - a[0].begin() + 1) * (a[2].end() - hed);
    }
    cout << ans << endl;
}