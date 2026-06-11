#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> C(N - 1), S(N - 1), F(N - 1);
    for(int i = 0; i < N - 1; i++) cin >> C[i] >> S[i] >> F[i];
    vector<int> dp(N, 0);
    for(int i = 0; i < N - 1; i++) dp[i] = S[i];
    for(int i = 0; i < N; i++){
        if(i == N - 1) cout << 0 << endl;
        else{
            if(dp[i] > S[i]) dp[i] = S[i];
            for(int j = i + 1; j < N - 1; j++){
                if(dp[j] > S[j]) dp[j] = S[j];
                if(dp[j] < dp[j - 1] + C[j - 1]) dp[j] = S[j] + (dp[j - 1] + C[j - 1] + F[j] - 1 - S[j]) / F[j] * F[j];
            }
            dp[N - 1] = dp[N - 2] + C[N - 2];
            cout << dp[N - 1] << endl;
        }
    }
}