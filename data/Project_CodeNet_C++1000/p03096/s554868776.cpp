#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

constexpr ll NMAX = 200010;
constexpr ll mod = 1e9+7;

int main(){
    ll N;
    cin >> N;
    vector<ll> C(N+1);
    rep(i, 1, N+1) cin >> C[i];
    vector<ll> seen(NMAX, -1);
    vector<ll> dp(N+1, 0);
    dp[0] = 1;
    rep(i, 1, N+1){
        dp[i] = dp[i-1];
        if(i != N && C[i] == C[i+1]) continue;
        if(seen[C[i]] != -1) dp[i] += dp[seen[C[i]]];
        dp[i] %= mod;
        seen[C[i]] = i;
        // cerr << "dp["  << i << "]: " << dp[i] << endl;
    }
    cout << dp[N] << endl;
    return 0;
}