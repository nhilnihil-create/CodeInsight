#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e9+7;
int dp[200005];
signed main() {
    int N;
    cin >> N;
    vector<int>cnt(200005,-1);
    vector<int>C(N);
    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        cin >> C[i];
        dp[i+1] += dp[i];
        if(i) {
            if(C[i] == C[i-1]) {
                goto END;
            }
        }
        if(cnt[C[i]] != -1) {
            dp[i+1] += dp[cnt[C[i]]+1];
        }
        dp[i+1] %= INF;
        END:;
        cnt[C[i]] = i;
    }
    cout << dp[N] << endl;
}