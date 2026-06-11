#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    int N = S.size(), M = T.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    rep(i, N) rep(j, M) {
        if(S[i] == T[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
        else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
    }
    string ans;
    int i = N, j = M;
    while(ans.size() < dp[N][M]) {
        if(S[i - 1] == T[j - 1]) {
            ans += S[i - 1];
            i--, j--;
        } else if(dp[i][j] == dp[i][j - 1]) j--;
        else i--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
