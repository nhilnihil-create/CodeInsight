#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    size_t K;
    cin >> K;
    size_t N{S.size()};
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(K + 1)));
    for(size_t i = 0; i < N; ++i)for(size_t j = 0; j <= K; ++j)dp[i][i][j] = 1;
    for(size_t j = 0; j <= K; ++j)for(size_t k = 1; k < N; ++k)for(size_t i = 0; i + k < N; ++i)
        dp[i][i + k][j] = max({dp[i][i + k - 1][j], dp[i + 1][i + k][j], (S[i] == S[i + k]) * (dp[i + 1][i + k - 1][j] + 2), (j != 0) * (dp[i + 1][i + k - 1][j - 1] + 2)});
    cout << dp[0][N - 1][K] << endl;
}