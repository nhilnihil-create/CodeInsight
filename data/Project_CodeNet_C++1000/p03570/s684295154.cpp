#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    vector<int> masks(n + 1), dp(n + 1, n);
    for (int i = 0; i < n; ++i) masks[i + 1] = masks[i] ^ (1 << (s[i] - 'a'));
    map<int, int> dps;
    dps[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        if (dps.find(masks[i]) != dps.end()) dp[i] = min(dp[i], dps[masks[i]] + 1);
        for (int j = 0; j < 26; ++j) {
            int target = masks[i] ^ (1 << j);
            if (dps.find(target) != dps.end()) dp[i] = min(dp[i], dps[target] + 1);
        }
        if (dps.find(masks[i]) == dps.end()) dps[masks[i]] = dp[i];
        else dps[masks[i]] = min(dps[masks[i]], dp[i]);
    }
    cout << dp[n] << "\n";
    return 0;
}
