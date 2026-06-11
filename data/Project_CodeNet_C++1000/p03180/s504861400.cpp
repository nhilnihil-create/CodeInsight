#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[i][j];
    }
    
    vector<ll> dp(1<<N, 0);
    for (int i = 0; i < (1<<N); i++) {
        for (int j = 0; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                if ((i>>j)&(i>>k)&1) dp[i] += A[j][k];
            }
        }
    }
    
    for (int i = 1; i < (1<<N); i++) {
        for (int j = ((i-1)&i); j > 0; j = ((j-1)&i)) {
            dp[i] = max(dp[i], dp[j]+dp[i-j]);
        }
    }
    cout << dp[(1<<N)-1] << endl;
    return 0;
}