#include <bits/stdc++.h>

#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<vector<int>> dp(N, vector<int>(26, 0));
    dp[0][S[0] - 'a'] = 1;
    for (int i = 1; i < N; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (S[i] == c)
                dp[i][c - 'a'] = dp[i - 1][c - 'a'] + 1;
            else
                dp[i][c - 'a'] = dp[i - 1][c - 'a'];
        }
    }

    int output = 0;
    for (int i = 0; i < N; i++) {
        int tmp = 0;
        for (int j = 0; j < 26; j++) {
            if (dp[i][j] > 0 && dp[N - 1][j] - dp[i][j] > 0) {
                tmp++;
            }
        }
        if (output < tmp) output = tmp;
    }

    cout << output << endl;

    return 0;
}
