#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < 30; ++i) {
        ll t = 1 << i;
        for (int j = 0; j < n; ++j) {
            c[j] = a[j] % (t << 1);
            d[j] = b[j] % (t << 1);
        }
        sort(d.begin(), d.end());
        int s = 0;
        for (int j = 0; j < n; ++j) {
            int left = lower_bound(d.begin(), d.end(), t - c[j]) - d.begin();
            int right = lower_bound(d.begin(), d.end(), 2 * t - c[j]) - d.begin();
            s += (right - left) % 2;
            left = lower_bound(d.begin(), d.end(), 3 * t - c[j]) - d.begin();
            right = lower_bound(d.begin(), d.end(), 4 * t - c[j]) - d.begin();
            s += (right - left) % 2;
        }
        if (s % 2) {
            ans += t;
        }
    }
    cout << ans;
    return 0;
}