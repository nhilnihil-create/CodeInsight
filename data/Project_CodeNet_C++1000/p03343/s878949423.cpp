
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    int ans = b[q - 1] - b[0];
    for (int i = q; i < n; i++) {
        vector<int> keks(n);
        for (int j = 0; j < n; j++) {
            if (a[j] < b[i - q + 1]) {
                keks[j] = 1;
            } else {
                if (a[j] <= b[i]) {
                    keks[j] = 2;
                }
            }
        }
        int cnt = 0;
        int len = 0;
        int good = 0;
        for (int j = 0; j < n; j++) {
            if (keks[j] == 2) {
                cnt++;
            }
            if (keks[j] != 1) {
                len++;
            }
            if (j + 1 == n || keks[j + 1] == 1) {
                good += max(0, min(len - k + 1, cnt));
                cnt = len = 0;
            }
        }
        if (good >= q) {
            ans = min(ans, b[i] - b[i - q + 1]);
        }
    }
    cout << ans;
    return 0;
}