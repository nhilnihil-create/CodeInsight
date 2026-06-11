#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;

string s, t;
int dp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s >> t;
    for (int i = 0; i <= s.length(); i++) {
        for (int j = 0; j <= t.length(); j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (s[i-1] == t[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    vector<char> ans;
    int i = s.length(), j = t.length();
    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            ans.push_back(s[i-1]);
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    for (int i = ans.size()-1; i >= 0; i--) cout << ans[i];
    cout << "\n";
    return 0;
}
