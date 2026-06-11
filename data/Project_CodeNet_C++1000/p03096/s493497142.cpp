#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9+7;

int main(){
    int N;
    cin >> N;
    vector<ll> dp(N+1, 0);
    dp[0] = 1;
    vector<int> pre(200001, -1);
    for (int i = 1; i <= N; i++) {
        int C;
        cin >> C;
        dp[i] += dp[i-1];
        if (pre[C] >= 1 && pre[C] <= i-2) dp[i] += dp[pre[C]];
        dp[i] %= mod;
        pre[C] = i;
    }
    cout << dp[N] << endl;
    return 0;
}