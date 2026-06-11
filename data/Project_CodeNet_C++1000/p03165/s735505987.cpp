#include<bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    int la = a.length(), lb = b.length();
    vector< vector< int > > dp(la + 1, vector< int > (lb + 1));
    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    //cout << dp[la][lb] << "\n";
    int i = la, j = lb;
    string ans = "";
    while (i >= 1 && j >= 1) {
        if (dp[i][j] != dp[i - 1][j] && dp[i][j] != dp[i][j - 1]) {
            ans = a[i - 1] + ans;
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j]) i--;
        else j--;
    }
    cout << ans << "\n";
}