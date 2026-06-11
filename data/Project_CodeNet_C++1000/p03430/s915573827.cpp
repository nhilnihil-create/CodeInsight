#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N, K;
    string S, T;
    cin >> S;
    N = (int)S.size();
    cin >> K;
    T = S;
    reverse(T.begin(), T.end());
    
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(K+1, 0)));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            bool same;
            if (S[i-1] == T[j-1]) same = true;
            else same = false;
            if (same) {
                for (int k = 0; k <= K; k++) {
                    dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i-1][j-1][k]+1);
                }
            }else {
                for (int k = 0; k <= K; k++) {
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]);
                    if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1]+1);
                }
            }
        }
    }
    int ans = 0;
    if (N%2 == 0) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= K; j++) {
                ans = max(ans, 2*dp[i][N-i][j]);
                if (i < N) ans = max(ans, 2*dp[i][N-1-i][j]+1);
            }
        }
    }else {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= K; j++) {
                ans = max(ans, 2*dp[i][N-i][j]);
                if (i < N) ans = max(ans, 2*dp[i][N-1-i][j]+1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}