//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;

typedef long long ll;

ll go(const vector<pair<int, int>> &a, const vector<pair<int, int>> &b) {
    int n = a.size();
    vector<bool> u(n, false);
    int ca = 0, cb = 0;
    ll ans = 0;
    ll bst = 0;
    while (true) {
        while (ca < n && u[a[ca].second]) ca++;
        while (cb < n && u[b[cb].second]) cb++;
        if (ca == n) {
            ans += max(b[cb].first, 0);
            break;
        }
        if (cb == n) {
            ans += max(a[ca].first, 0);
            break;
        }
        int df = a[ca].first + b[cb].first;
        if (df > 0) {
            bst = max(bst, ans + max(a[ca].first, b[cb].first));
            u[a[ca].second] = u[b[cb].second] = true;
            ans += df;
            continue;
        } else {
            ans += max(0, max(a[ca].first, b[cb].first));
            break;
        }
    }
    return max(bst, ans);
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i] = make_pair(x * 2, i);
        b[i] = make_pair(-y * 2, i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    cout << go(a, b) << "\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
    solve();
    //solve();
#endif
    solve();
    return 0;
}