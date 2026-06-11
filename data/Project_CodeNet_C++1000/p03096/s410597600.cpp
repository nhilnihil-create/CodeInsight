#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1000000007;

int main(){
    int N; cin >> N;
    vector<int> C(N);
    rep(i, N) cin >> C[i];
    vector<int> dp(N+1);
    map<int, int> d;
    dp[0] = 1;
    rep(i, N) {
        dp[i+1] = dp[i];
        if (i > 0 && C[i-1] == C[i]){
            continue;
        }
        if(d[C[i]] > 0){
            dp[i+1] += dp[d[C[i]]];
        }
        d[C[i]] = i+1;
        dp[i+1] %= MOD;
    }
    cout << dp[N] << endl;
    return 0;
}
