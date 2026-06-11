#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

bool debug = 0;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> bc(m);
    for (int i = 0; i < m; i++) cin >> bc[i].second >> bc[i].first;
    sort(a.begin(), a.end());
    sort(bc.begin(), bc.end(), greater<pair<int, int>>());
    int idx = 0;
    for (int i = 0; i < m; i++) {
        for (int j = idx; j < idx + bc[i].second; j++) {
            if (j >= n) break;
            if (a[j] < bc[i].first) a[j] = bc[i].first;
        }
        idx += bc[i].second;
        if (idx >= n) break;
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    cout << sum << endl;
}

int main() {
    if (debug) {
        while (true) {
            cout << "********" << endl;
            solve();
        }
    } else {
        solve();
    }
    return 0;
}