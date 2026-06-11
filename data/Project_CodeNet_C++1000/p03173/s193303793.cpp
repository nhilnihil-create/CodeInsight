#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> sum(N);
    sum[0] = A[0];
    for (int i = 1; i < N; i++) sum[i] = sum[i-1]+A[i];
    vector<vector<ll>> dp(N, vector<ll>(N, (ll)1e18));
    for (int i = 0; i < N; i++) dp[i][i] = 0;
    for (int l = 2; l <= N; l++) {
        for (int i = 0; i+l-1 <= N-1; i++) {
            ll all = sum[i+l-1];
            if (i > 0) all -= sum[i-1];
            for (int j = i+1; j <= i+l-1; j++) {
                dp[i][i+l-1] = min(dp[i][i+l-1], all+dp[i][j-1]+dp[j][i+l-1]);
            }
        }
    }
    cout << dp[0][N-1] << endl;
    return 0;
}