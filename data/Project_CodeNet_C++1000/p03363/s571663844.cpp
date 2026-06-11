#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, sum = 0, ans = 0;
    cin >> n;
    vector<int64_t> a(n);
    map<int64_t, int64_t> cnt;
    for (auto i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) cnt[0]++;
        sum += a[i], ans += cnt[sum], cnt[sum]++;
    }
    cout << ans << endl;
    return 0;
}