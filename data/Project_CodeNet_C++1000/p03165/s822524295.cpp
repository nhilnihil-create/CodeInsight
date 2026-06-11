#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s, t;    cin >> s >> t;
    long long l_s = s.length(), l_t = t.length();
    vector<vector<int> > dp(l_s+1, vector<int>(l_t+1, 0));

    for (int i = 0; i < l_s; i++) {
        for (int j = 0; j < l_t; j++) {
            if (s[i] == t[j])
                dp[i+1][j+1] = max(dp[i][j]+1, dp[i+1][j+1]);
            dp[i+1][j+1] = max(dp[i+1][j], dp[i+1][j+1]);
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j+1]); 
        }
    }

    string res = "";
    int i = l_s, j = l_t;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j])
            i--;
        else if (dp[i][j] == dp[i][j-1])
            j--;
        else {
            res = s[i-1] + res;
            i--;
            j--;
        }
    }

    cout << res << endl;

    return 0;
}