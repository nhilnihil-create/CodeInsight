#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S; cin >> S;
    vector<ll> dp(4);
    dp[0] = 1;
    for (char c : S) {
        if (c == 'A') {
            dp[1] = (dp[1] + dp[0]) % MOD;
        }
        else if (c == 'B') {
            dp[2] = (dp[2] + dp[1]) % MOD;
        }
        else if (c == 'C') {
            dp[3] = (dp[3] + dp[2]) % MOD;
        }
        else {
            dp[3] = (dp[3] * 3 + dp[2]) % MOD;
            dp[2] = (dp[2] * 3 + dp[1]) % MOD;
            dp[1] = (dp[1] * 3 + dp[0]) % MOD;
            dp[0] = (dp[0] * 3) % MOD;
        }
    }
    cout << dp[3] << "\n";
}