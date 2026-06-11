#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, ans = 0, prev = 0, cnt = 0;
    cin >> n;
    vector<int64_t> a(n), s(n + 1, 0);
    for (auto i = 0; i < n; i++) {
        cin >> a[i];
        s[i + 1] = a[i] + s[i];
    }
    sort(s.begin(), s.end());
    for (auto i = 0; i < (int)s.size(); i++) {
        if (s[i] != prev) {
            ans += cnt * (cnt - 1) / 2;
            prev = s[i], cnt = 1;
            continue;
        }
        cnt++;
        if (i == (int)s.size() - 1)
            ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
