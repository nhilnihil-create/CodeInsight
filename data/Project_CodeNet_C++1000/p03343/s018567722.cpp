#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()
#define int long long

using namespace std;

int a[5010];

vector <pair <int, int>> v;

int kok[5010];
int pref[5010];

vector <int> sok;

int ans = 1e18;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.pb({a[i], i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= n - q; i++) {
        int l = i, r = i + q;
        while (l > 0 && v[l].first == v[l - 1].first)
            --l;
        while (r < n && v[r - 1].first == v[r].first)
            ++r;
        sok.clear();
        for (int j = 0; j < l; j++)
            sok.pb(v[j].second);
        sort(sok.begin(), sok.end());
        for (int j = 0; j <= n; j++) {
            kok[j] = 0;
            pref[j] = 0;
        }
        for (int j = l; j < r; j++) {
            kok[v[j].second] = 1;
        }
        for (int j = 1; j <= n; j++) {
            pref[j] = pref[j - 1] + kok[j - 1];
        }
        int nch = 0;
        int tot = 0;
        for (int j = 0; j < sz(sok); j++) {
            if (pref[sok[j]] - pref[nch] > 0 && sok[j] - nch - pref[sok[j]] + pref[nch] < k - 1) {
                tot += min(((k - 1) - (sok[j] - nch - pref[sok[j]] + pref[nch])), pref[sok[j]] - pref[nch]);
            }
            nch = sok[j] + 1;
        }
        if (pref[n] - pref[nch] > 0 && n - nch - pref[n] + pref[nch] < k - 1) {
            tot += min((k - 1) - (n - nch - pref[n] + pref[nch]), pref[n] - pref[nch]);
        }
        if (r - l - tot >= q)
            ans = min(ans, v[r - 1].first - v[l].first);
    }
    cout << ans << endl;
    return 0;
}
