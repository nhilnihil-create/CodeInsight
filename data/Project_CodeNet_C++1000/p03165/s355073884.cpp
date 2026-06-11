#include <bits/stdc++.h>

using namespace std;

const int MAX_LENGTH = 3012;
string s, t, dp[2][MAX_LENGTH];

int main() {

    cin >> s >> t;

    int s_length = s.size(), t_length = t.size();

    if (s[0] == t[0])
        dp[0][0] = s[0];

    for (int i = 1; i < t_length; ++i) {

        if (t[i] == s[0] && dp[0][i - 1].empty())
            dp[0][i] = s[0];

        else
            dp[0][i] = dp[0][i - 1];
    }

    int tst = 0;

    for (int i = 1; i < s_length; ++i) {

        if (tst % 2 == 0) {
            if (s[i] == t[0] && dp[0][0].size() == 0)
                dp[1][0] = s[i];

            else
                dp[1][0] = dp[0][0];
        }

        else {
            if (s[i] == t[0] && dp[1][0].size() == 0)
                dp[0][0] = s[i];

            else
                dp[0][0] = dp[1][0];
        }

        for (int j = 1; j < t_length; ++j) {

            if (tst % 2 == 0) {

                if (s[i] == t[j])
                    dp[1][j] = dp[0][j - 1] + s[i];

                else if (dp[1][j - 1].size() > dp[0][j].size())
                    dp[1][j] = dp[1][j - 1];

                else
                    dp[1][j] = dp[0][j];
            }
            else {

                if (s[i] == t[j])
                    dp[0][j] = dp[1][j - 1] + s[i];

                else if (dp[0][j - 1].size() > dp[1][j].size())
                    dp[0][j] = dp[0][j - 1];

                else
                    dp[0][j] = dp[1][j];
            }
        }
        tst++;
    }

    if (dp[0][t_length - 1].size() > dp[1][t_length - 1].size())
        cout << dp[0][t_length - 1] << endl;

    else
        cout << dp[1][t_length - 1] << endl;
    return 0;
}