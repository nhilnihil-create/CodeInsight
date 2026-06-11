
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;

const ll MOD_CONST = 1000000007;
const string ABC = "ABC";

int main()
{
    string s;
    cin >> s;

    vector<vector<ll>> dp(s.length() + 1, vector<ll>(4));

    for (int i = s.length(); i >= 0; i--) {
        for (int j = 3; j >=0; j--) {
            if (i == s.length()) {
                if (j == 3) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = 0;
                }
            }
            else {
                if (j == 3) {
                    if (s[i] == '?') {
                        dp[i][j] =(3* dp[i + 1][j])%MOD_CONST;
                    }
                    else {
                        dp[i][j] = (dp[i + 1][j]) % MOD_CONST;
                    }
                }
                else {
                    int m1 = (s[i] == '?') ? 3 : 1;
                    int m2 = (s[i] == '?' || s[i] == ABC[j]) ? 1 : 0;

                    dp[i][j] = ((m1 * dp[i + 1][j]) % MOD_CONST + m2 * dp[i + 1][j + 1]) % MOD_CONST;

                }
            }
        }
    }
    cout << dp[0][0] << endl;
}  

