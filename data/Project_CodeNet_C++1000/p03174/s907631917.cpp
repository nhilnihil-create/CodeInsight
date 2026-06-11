#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[i][j];
    }
    
    ll mod = 1e9+7;
    vector<vector<ll>> dp(N+1, vector<ll>((1<<N), 0));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < (1<<N); j++) {
            if (__builtin_popcount(j) != i) continue;
            for (int k = 0; k < N; k++) {
                if (((j>>k)&1) == 0) continue;
                if (A[i-1][k] == 0) continue;
                dp[i][j] += dp[i-1][j-(1<<k)];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[N][(1<<N)-1] << endl;
    return 0;
}