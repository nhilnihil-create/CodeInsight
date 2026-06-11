#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int mn = 1e5;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min (mn, a[i]);
        sum += a[i];
    }
    a[n] = mn;
    int mn2 = 1e5;
    int ans = mn;
    for (int i = 0; i <= n; i++) {
        a[i] -= mn;
        sum -= mn;
    }
    sum += mn;
    mn = 0;
    while (sum) {
        for (int i = 0; i <= n; i++) {
            if (a[i] == mn && mn2 != 1e5) {
                ans += mn2;
                for (int j = i - 1; j >= 0; j--) {
                    if (a[j] == mn) {
                        break;
                    }
                    a[j] -= mn2;
                    sum -= mn2;
                }
                mn2 = 1e5;
            }
            if (a[i]) {
                mn2 = min (mn2, a[i]);
            }
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
