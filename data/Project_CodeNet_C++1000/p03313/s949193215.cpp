#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int sz = (1 << n);
    vector<int> a(sz);
    for (int i = 0; i < sz; i++) cin >> a[i];
    a.push_back(0);
    vector<P> dp(sz, P(sz, sz));
    for (int i = 0; i < sz; i++) {
        dp[i].first = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz; j++) {
            if (j & (1 << i)) {
                int k = (j ^ (1 << i));
                vector<int> v = {dp[j].first, dp[j].second, dp[k].first, dp[k].second};
                sort(v.begin(), v.end(), [&](int i1, int i2){
                    return a[i1] > a[i2];
                });
                dp[j].first = v[0];
                dp[j].second = v[1];
            }
        }
    }

    int ans = a[dp[0].first] + a[dp[0].second];
    for (int i = 1; i < sz; i++) {
        ans = max(ans, a[dp[i].first] + a[dp[i].second]);
        cout << ans << "\n";
    }
    return 0;
}