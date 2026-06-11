#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
void solve () {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 1e9;
    for (int i = 0, j = k - 1; j < n; i++, j++) {
        ans = min (ans, a[j] - a[i]);
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
