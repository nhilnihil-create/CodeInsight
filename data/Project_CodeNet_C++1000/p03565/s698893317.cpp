#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    string S;
    string T;

    cin >> S >> T;

    vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1));
    for (int i = 0; i < S.size(); i++) {
        dp[i][0] = 1;
    }

    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < T.size(); j++) {
            if (S.at(i) == T.at(j) || S.at(i) == '?') {
                dp[i + 1][j + 1] += dp[i][j];
            }
        }
    }

    // rep(i, S.size() + 1) {
    //     rep(j, T.size() + 1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    bool flg = false;
    int last_i = 0;
    for (int i = 0; i < S.size(); i++) {
        if (dp[i + 1][T.size()] != 0) {
            flg = true;
            last_i = i;
        }
    }

    if (flg) {
        // cout << "last_i: " << last_i << endl;
        for (int j = 0; j < T.size(); j++) {
            // cout << S.at(last_i - T.size() + 1 + j) << endl;
            // cout << T.at(j) << endl;

            S.at(last_i - T.size() + 1 + j) = T.at(j);
        }

        for (int i = 0; i < S.size(); i++) {
            if (S.at(i) == '?') S.at(i) = 'a';
        }
        cout<< S << endl;
    } else {
        cout << "UNRESTORABLE" << endl;
    }

}