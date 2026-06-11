#include <bits/stdc++.h>
using namespace std;

int dp[300][300][302];
void chmax(int& a, int b){
    a = max(a, b);
}

int main(){
    string S;
    int K;
    cin >> S >> K;
    int N = S.size();

    for(int i=0; i<N; i++) dp[i][i][0] = 1;
    for(int i=0; i<N-1; i++){
        if(S[i] == S[i+1]){
            dp[i][i+1][0] = 2;
        }else{
            dp[i][i+1][0] = 1;
            dp[i][i+1][1] = 2; 
        }
    }
    for(int d=2; d<N; d++){
        for(int i=0; i+d<N; i++){
            for(int k=0; k<=K; k++){
                chmax(dp[i][i+d][k], max(dp[i][i+d-1][k], dp[i+1][i+d][k]));
                chmax(dp[i][i+d][k + (S[i] != S[i+d])], dp[i+1][i+d-1][k] + 2);
            }
        }
    }
    int ans = 0;
    for(int k=0; k<=K; k++) chmax(ans, dp[0][N-1][k]);
    cout << ans << endl;
    return 0;
}