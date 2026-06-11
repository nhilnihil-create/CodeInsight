#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string S;
    cin >> S;
    int N = (int)S.size();
    const int MOD = 1e9 + 7;
    vector<vector<long long>> dp(3, vector<long long> (N));
    long long size = 1;
    if(S[0] == 'A') dp[0][0] = 1;
    else if(S[0] == '?'){
        dp[0][0] = 1;
        size = 3;
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < 3; j++){
            if(S[i] == 'A'){
                if(j == 0) dp[j][i] = dp[j][i - 1] + size;
                else dp[j][i] = dp[j][i - 1];
            }
            else if(S[i] == 'B'){
                if(j == 1) dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1];
                else dp[j][i] = dp[j][i - 1];
            }
            else if(S[i] == 'C'){
                if(j == 2) dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1];
                else dp[j][i] = dp[j][i - 1];
            }
            else {
                if(j == 0) dp[j][i] = dp[j][i - 1] * 3 + size;
                else if(j == 1) dp[j][i] = dp[j][i - 1] * 3 + dp[j - 1][i - 1];
                else if(j == 2) dp[j][i] = dp[j][i - 1] * 3 + dp[j - 1][i - 1];
            }
        }
        for(int j = 0; j < 3; j++) dp[j][i] %= MOD;
        if(S[i] == '?') size *= 3;
        size %= MOD;
    }
    cout << dp[2][N - 1] << endl;
}