#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N;
ll C[200010];
ll dp[200010];
ll add[200010];

ll solve(){
    dp[0] = 1;
    REP(i, N){
        if(i > 0 && C[i] == C[i - 1]){
            dp[i + 1] = dp[i];
            continue;
        }
        dp[i + 1] = (dp[i] + add[C[i]]) % MOD;
        add[C[i]] = (add[C[i]] + dp[i]) % MOD;
    }
    return dp[N];
}

signed main(){
    cin >> N;
    REP(i, N){
        cin >> C[i];
        C[i]--;
    }
    PRINT(solve());
    return 0;
}