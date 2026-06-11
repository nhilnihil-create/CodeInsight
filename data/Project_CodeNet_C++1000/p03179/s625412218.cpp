#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    vector<vector<int>> dp(N + 1, vector<int>(N));
    for(int i = 0;i < N;i++) dp[1][i] = 1;
    for(int i = 1;i < N;i++){
        if(S[i - 1] == '<'){
            int tmp = 0;
            for(int j = 0;j < N - i;j++){
                (tmp += dp[i][j]) %= mod;
                (dp[i + 1][j] = tmp) %= mod;
            }
        }
        else{
            int tmp = dp[i][N - i];
            for(int j = N - i - 1;j >= 0;j--){
                (dp[i + 1][j] += tmp) %= mod;
                (tmp += dp[i][j]) %= mod;
            }
        }
    }
    cout << dp[N][0] << endl;
    return 0;
}
