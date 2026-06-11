#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7;

int main() {
    int N;
    cin >> N;
    int A[2][N];
    for(int i=0; i<2; i++) for(int j=0; j<N; j++) cin >> A[i][j];
    int dp[2][N];

    dp[0][0] = A[0][0];
    dp[1][0] = dp[0][0] + A[1][0];

    for(int j=1; j<N; j++) {
        dp[0][j] = dp[0][j-1] + A[0][j];
        dp[1][j] = max(dp[0][j] + A[1][j], dp[1][j-1] + A[1][j]);
    }
    cout << dp[1][N-1] << endl;
}