#include <bits/stdc++.h>
using namespace std;
 
int main(void) {
    string s;
    cin >> s;
 
    int n = s.length();
    int mask = 0;
    int ans = n;
    unordered_map<int, int> dp;
    dp[0] = 0;
    for (int i = 0; i < n; ++ i) {
        mask ^= 1<<(s[i] - 'a');
        if (dp.find(mask) != end(dp)) ans = dp[mask];
        else ans = n;
 
        for (int j = 0; j < 26; ++ j) if (dp.find(mask ^ (1<<j)) != end(dp)) {
            ans = min(ans, dp[mask ^ (1<<j)] + 1);
        }
        if (dp.find(mask) == end(dp)) dp[mask] = ans;
        else if (dp[mask] > ans) dp[mask] = ans;
    }
    if (ans == 0) ++ ans;
    cout << ans << endl;
 
    return 0;
}