#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    int ans = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
        if (a[i] - a[i - 1] > 0) {
            ans += a[i] - a[i - 1];
        }

    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
