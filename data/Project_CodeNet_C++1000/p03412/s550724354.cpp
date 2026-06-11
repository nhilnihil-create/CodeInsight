#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int ans = 0;
    for (int bit = 0; bit < 29; ++bit) {
        const int mod = 1 << (bit + 1), k = 1 << bit;
        vector<int> ta(n), tb(n);
        for (int i = 0; i < n; ++i) {
            ta[i] = a[i] & (mod - 1);
            tb[i] = b[i] & (mod - 1);
        }
        sort(tb.begin(), tb.end());
        int tot = 0;
        for (int i = 0; i < n; ++i) {
            [&]() {
                auto itl = lower_bound(tb.begin(), tb.end(), k - ta[i]);
                auto itr = upper_bound(tb.begin(), tb.end(), mod - ta[i] - 1);
                if (itl == tb.end() || itr == tb.begin()) return;
                if (itl >= itr) return;
                tot = (tot + (itr - itl)) % 2;
            }();
            [&]() {
                auto it = lower_bound(tb.begin(), tb.end(), mod - ta[i] + k);
                if (it == tb.end()) return;
                tot = (tot + (tb.end() - it)) % 2;
            }();
        }
        if (tot & 1) ans |= 1 << bit;
    }
    cout << ans << '\n';
    return 0;
}
