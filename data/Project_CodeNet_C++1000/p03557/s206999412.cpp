#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        auto Iter1 = lower_bound(a.begin(), a.end(), b[i]);
        auto Iter2 = upper_bound(c.begin(), c.end(), b[i]);
        cnt += (Iter1 - a.begin()) * (c.end() - Iter2);
    }
    cout << cnt << '\n';
    return 0;
}