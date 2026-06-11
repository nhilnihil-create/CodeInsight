#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> C(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> C[i];
    }
    int CMAX = 2e5+1;
    vector<int> pc(CMAX, -1);

    const ll MOD = 1e9 + 7;
    auto Add = [&](ll& x, ll y) { x = ( x + y % MOD ) % MOD; };
    auto Mul = [&](ll& x, ll y) { x = ( x * y % MOD ) % MOD; };
    auto Pow = [&](ll x, ll n) -> ll {
        ll t = x % MOD, r = 1;
        while ( n > 0 ) {
            if ( n & 1 ) Mul(r, t);
        Mul(t, t);
        n >>= 1;
        }
        return r;
    };
    auto Inv = [&](ll a) -> ll {
        return Pow(a, MOD - 2);
    };
    
    vector<ll> dp(N);
    dp[0] = 1;
    pc[C[0]] = 0;
    for ( int i = 1; i < N; i++ ) {
        dp[i] = dp[i-1];
        int pi = pc[C[i]];
        if ( pi >= 0 && i - pi >= 2 ) {
            Add(dp[i], dp[pi]);
        }
        pc[C[i]] = i;
    }
    return dp[N-1];
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}