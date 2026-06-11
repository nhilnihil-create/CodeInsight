#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1));
    for (int i = 1; i <= (int)s.size(); i++)
        for (int j = 1; j <= (int)t.size(); j++) {
            if (dp[i][j] < dp[i-1][j])
                dp[i][j] = dp[i-1][j];
            if (dp[i][j] < dp[i][j-1])
                dp[i][j] = dp[i][j-1];
            int base = dp[i-1][j-1];
            if (s[i-1] == t[j-1]) {
                if (dp[i][j] < base + 1)
                    dp[i][j] = base + 1;
            }
        }
    int i = s.size();
    int k = t.size();
    int len = dp[i][k];
    string ans(len, 'a');
    while (len) {
        if (s[i-1] == t[k-1]) {
            ans[--len] = s[--i];
            k--;
        } else {
            if (dp[i][k] == dp[i-1][k])
                i--;
            else
                k--;
        }
    }
    cout << ans;
    return 0;
}