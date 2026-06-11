#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    string S;
    cin >> S;
    int N = (unsigned int)S.size();
    const int MOD = 1000000007;

    vector<vector<ll>> dp((unsigned int)N + 1, vector<ll>(4));
    for (int i = N; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if (i == N) {
                dp[i][j] = (j == 3 ? 1 : 0);
            } else {
                dp[i][j] = dp[i + 1][j] * (S[i] == '?' ? 3 : 1);
                if (j < 3 && (S[i] == '?' || S[i] == "ABC"[j])) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}