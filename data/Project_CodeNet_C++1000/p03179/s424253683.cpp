#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    ll mod = 1e9+7;
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<ll>> dp(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) dp[0][i] = 1;
    
    for (int i = 1; i < N; i++) {
        if (S[i-1] == '<') {
            dp[i][0] = dp[i-1][0];
            for (int j = 1; j < N-i; j++) dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
        }else {
            dp[i][N-i-1] = dp[i-1][N-i];
            for (int j = N-i-2; j >= 0; j--) dp[i][j] = (dp[i-1][j+1]+dp[i][j+1])%mod;
        }
    }
    cout << dp[N-1][0] << endl;
    return 0;
}