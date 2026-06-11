#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXS = 10000;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> idxs(n), w(n), s(n);
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> s[i] >> v[i];
        idxs[i] = i;
    }
    sort(idxs.begin(), idxs.end(), [&](const int i1, const int i2){return w[i1] + s[i1] < w[i2] + s[i2];});

    ll ans = 0;
    vector<ll> dp(MAXS + 1, 0);
    for (int i : idxs) {
        for (int j = s[i]; j >= 0; j--) {
            ans = max(ans, dp[j] + v[i]);
            if (j + w[i] <= MAXS) dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
        }
    }
    
    for (int i = 0; i <= MAXS; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}