#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int n, m;
ll ans;
ii a[N];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        int d = min(m, a[i].second);
        m -= d;
        ans += 1LL * a[i].first * d;
        if (!m)
            break;
    }
    cout << ans << endl;
    return 0;
}
