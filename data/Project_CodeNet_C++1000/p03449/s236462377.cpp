#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<vector<int>> A(2, vector<int>(N, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> dp(2, vector<int>(N, -1));
    dp[0][0] = A[0][0];
    dp[1][0] = A[0][0] + A[1][0];
    for (int i = 1; i < N; ++i) {
        dp[0][i] = dp[0][i - 1] + A[0][i];
        dp[1][i] = max(dp[1][i - 1], dp[0][i]) + A[1][i];
    }
    cout << dp[1][N - 1] << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
