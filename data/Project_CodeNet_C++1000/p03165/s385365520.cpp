#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, len;
#define inf 1000000000
ll dp[3005][3005];

string solve(string &s, string &t) {
    int i = 0, j = 0;
    string ans = "";
    while(len > 0) {
        if(s[i] == t[j]) {ans += s[i]; ++i, ++j, --len;}
        else {
            if(dp[i][j + 1] > dp[i + 1][j]) ++j;
            else ++i;
        }
    }
    return ans;
}

int dpp(string &s, string &t, int i, int j) {
    if(i >= n || j >= m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) return dp[i][j] = 1 + dpp(s, t, i + 1, j + 1);
    else return dp[i][j] = max(dpp(s, t, i + 1, j), dpp(s, t, i, j + 1));
}


int main() {
    string s, t;
    cin >> s >> t;
    memset(dp, -1, sizeof dp);
    n = s.size(), m = t.size();
    len = dpp(s, t, 0, 0);
    cout << solve(s, t);
}
