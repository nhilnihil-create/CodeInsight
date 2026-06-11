#include <iostream>

using namespace std;

int dp[300][300][301];

const int INF = 1e+5;

int main(){
    string S;
    int K;
    cin >> S;
    cin >> K;
    int N = S.size();
    for(int i = 0; i < N-1; i++){
        if(S[i] == S[i+1]) dp[i][i+1][2] = 0;
        else dp[i][i+1][2] = 1;
    }
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }
    for(int k = 2; k <= N; k++){
        for(int i = 2; i < N; i++){
            for(int j = 0; i+j < N; j++){
                if(i+1 < k) continue;
                if(S[j] == S[j+i]) dp[j][j+i][k] = dp[j+1][j+i-1][k-2];
                else dp[j][j+i][k] = dp[j+1][j+i-1][k-2]+1;
                if(k <= i)dp[j][j+i][k] = min(min(dp[j+1][j+i][k], dp[j][j+i-1][k]), dp[j][j+i][k]);
                //cout << j << ' ' << j+i << ' ' << k << ' ' << dp[j][j+i][k] << endl;
            }
        }
    }
    int ans = 0;
    for(int k = 0; k <= N; k++){
        //cout << dp[0][N-1][k] << endl;
        if(dp[0][N-1][k] <= K) ans = k;
    }
    cout << ans << endl;
}