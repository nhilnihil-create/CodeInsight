#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    string s, t;
    cin >> s >> t;

    int ss = s.size(), ts = t.size();
    int dp[ss + 1][ts + 1];
    for(int i = 0; i <= ss; i++)
        for(int j = 0; j <= ts; j++) dp[i][j] = 0;

    for(int i = 0; i < ss; i++) {
        for(int j = 0; j < ts; j++) {
            dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            if(s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
        }
    }

    string ans;
    while(ss > 0 && ts > 0) {
        if(dp[ss][ts] == dp[ss - 1][ts]) {
            ss--;
        } else if(dp[ss][ts] == dp[ss][ts - 1]) {
            ts--;
        } else {
            ans = s[ss - 1] + ans;
            ss--;
            ts--;
        }
    }
    cout << ans << "\n";
}