#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, K, M;
ll A[100010];
ll cnt[100], K2[100], pow2[100];
ll dp[100][2];

ll solve(){
    ll ret = 0;
    for(int i = 64; i >= 0; i--){
        dp[i][0] = dp[i + 1][0] + K2[i] * (N - cnt[i]) * pow2[i] + (1 - K2[i]) * cnt[i] * pow2[i];
        if(i < M) dp[i][1] = dp[i + 1][1] + max(cnt[i], N - cnt[i]) * pow2[i];
        if(K2[i] == 1) dp[i][1] = max(dp[i][1], dp[i + 1][0] + cnt[i] * pow2[i]);
    }
    return max(dp[0][0], dp[0][1]);
}

signed main(){
    cin >> N >> K;
    REP(i, N) cin >> A[i];
    REP(i, 64){
        REP(j, N){
            if(A[j] % 2 == 1) cnt[i]++;
            A[j] /= 2;
        }
        if(K % 2 == 1){
            K2[i] = 1;
            M = i;
        }
        K /= 2;
    }
    pow2[0] = 1;
    REP(i, 64) pow2[i + 1] = pow2[i] * 2;
    PRINT(solve());
    return 0;
}