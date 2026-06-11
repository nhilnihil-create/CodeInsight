#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int N, K;
    cin >> N >> K;
    ll mod = 1e9+7;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    vector<vector<ll>> dp(N+1, vector<ll>(K+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        ll sum = 0;
        for (int j = 0; j <= K; j++) {
            sum += dp[i][j];
            if (j >= A[i]+1) sum -= dp[i][j-A[i]-1];
            if (sum < 0) sum += mod;
            dp[i+1][j] = sum%mod;
        }
    }
    cout << dp[N][K] << endl;
    return 0;
}