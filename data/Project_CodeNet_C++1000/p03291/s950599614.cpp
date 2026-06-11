#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

int main() {
    string s;
    cin >> s;
    int len = (int)s.size();
    
    vector<vector<long long>> dp(len + 1, vector<long long>(4));
    dp.at(0).at(0) = 1;
    for (int i = 0; i < len; i++) {
        if (s.at(i) == '?') {
            for (int j = 0; j < 4; j++) {
                dp.at(i + 1).at(j) += dp.at(i).at(j) * 3 % MOD;
                dp.at(i + 1).at(j) %= MOD;
            }
            for (int j = 1; j < 4; j++) {
                dp.at(i + 1).at(j) += dp.at(i).at(j - 1);
            }
        }
        else {
            for (int j = 0; j < 4; j++) {
                dp.at(i + 1).at(j) += dp.at(i).at(j);
            }
            if (s.at(i) == 'A') dp.at(i + 1).at(1) += dp.at(i).at(0);
            else if (s.at(i) == 'B') dp.at(i + 1).at(2) += dp.at(i).at(1);
            else dp.at(i + 1).at(3) += dp.at(i).at(2);
        }

        for (int j = 0; j < 4; j++) {
            dp.at(i + 1).at(j) %= MOD;
        }
    }
    cout << dp.at(len).at(3) << endl;
}  