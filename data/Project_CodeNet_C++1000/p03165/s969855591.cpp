#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define nax 3042
using namespace std;

array <int, 3> dp[nax][nax]; // {size_of_lcs, prevI, prevJ}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = t.size() - 1; j >= 0; j--) {
            if (s[i] == t[j]) {
                dp[i][j] = {dp[i + 1][j + 1][0] + 1, i + 1, j + 1};
            }
            else if (dp[i + 1][j][0] > dp[i][j + 1][0]) {

                dp[i][j] = {dp[i + 1][j][0], i + 1, j};
            }
            else {
                dp[i][j] = {dp[i][j + 1][0], i, j + 1};
            }
        }
    }

    string lcs = "";
    for (int i = 0, j = 0; i < s.size() && j < t.size();) {
        if (dp[i][j][1] == i + 1 && dp[i][j][2] == j + 1) {
            lcs += string(1, s[i]);
        }
        int tempI = dp[i][j][1];
        j = dp[i][j][2];
        i = tempI;
    }

    cout << lcs << "\n";
}