#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll N; cin >> N;
    vector<ll> dp(N+1, N);
    dp[0] = 0;
    for (int i=0; i<N; ++i){
        dp[i+1] = min(dp[i+1], dp[i]+1);
        for (int j=6; i+j<=N; j*=6) dp[i+j] = min(dp[i+j], dp[i]+1);
        for (int j=9; i+j<=N; j*=9) dp[i+j] = min(dp[i+j], dp[i]+1);
    }
    cout << dp[N] << endl;
    return 0;
}