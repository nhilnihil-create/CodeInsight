#include <bits/stdc++.h>
using namespace std;


int main() {
    string S;
    string T;
    cin >> S;
    cin >> T;

    int num_S = S.size();
    int num_T = T.size();
    
    vector<vector<int>> dp(num_S + 1, vector<int>(num_T + 1, 0));
    for (int i = 1; i < num_S + 1; i++) {
        for (int j = 1; j < num_T + 1; j++) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    int num_ans = dp[num_S][num_T];
    int i = num_S - 1;
    int j = num_T - 1;
    string ans = "";

    while (num_ans > 0) {
        if (S[i] == T[j]) {
            ans += S[i];
            i--;
            j--;
            num_ans--;
        }
        else if (dp[i + 1][j + 1] == dp[i][j + 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}