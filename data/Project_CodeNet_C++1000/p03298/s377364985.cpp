#include <cstring>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    string S; cin >> S;
    long long ans = 0;
    for (int s = 0; s < 1<<n; s++) {
        string r, b;
        for (int i = 0; i < n; i++)
            if ((s >> i) & 1) b.push_back(S[i]);
            else r.push_back(S[i]);
        const int rl = r.size(), bl = b.size();
        long long dp[rl+1][bl+1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i <= rl; i++) {
            for (int j = 0; j <= bl; j++) {
                if (i == 0 && j == 0) { dp[0][0] = 1; continue; }
                const char c = S[2*n-i-j];
                long long tmp = 0;
                if (i > 0 && r[i-1] == c) tmp += dp[i-1][j];
                if (j > 0 && b[j-1] == c) tmp += dp[i][j-1];
                dp[i][j] = tmp;
            }
        }
        ans += dp[rl][bl];
    }
    cout << ans << endl;
}