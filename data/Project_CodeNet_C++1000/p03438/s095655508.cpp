#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, b, cnt = 0, as = 0, bs = 0;
    cin >> n;
    vector<int64_t> a(n);
    for (auto i = 0; i < n; i++) {
        cin >> a[i];
        as += a[i];
    }
    for (auto i = 0; i < n; i++) {
        cin >> b;
        bs += b;
        if (a[i] < b) cnt += ((b - a[i]) + 1) / 2;
    }
    // cout << as << " " << bs << " " << cnt << endl;
    if (bs - as >= cnt) cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
