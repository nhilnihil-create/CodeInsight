#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

#define BIGNUMBER 1000000007

using namespace std;

int main(void) {
    string S;
    cin >> S;

    vector<vector<ll>> dp(S.size()+1, vector<ll>(4, 0));
    dp[S.size()][3] = 1;
    int m, m1, m2;
    for (int i = S.size()-1; i >= 0; i--) {
        if (S[i] == '?') {
            m = 3;
            m1 = 3;
        }
        else {
            m = 1;
            m1 = 1;
        }
        dp[i][3] = (m * dp[i+1][3]) % BIGNUMBER;
        for (int j = 2; j >= 0; j--) {
            if (S[i] == '?' || S[i] == "ABC"[j]) {
                m2 = 1;
            }
            else {
                m2 = 0;
            }
            dp[i][j] = ((m1 * dp[i+1][j]) % BIGNUMBER + (m2 * dp[i+1][j+1]) % BIGNUMBER) % BIGNUMBER;
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}