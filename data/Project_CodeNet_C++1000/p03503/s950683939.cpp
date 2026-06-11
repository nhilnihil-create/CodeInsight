#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, F[200], P[200][20];

ll solve(ll st){
    ll ret = 0;
    REP(i, N){
        ll c = bitset<10>(st & F[i]).count();
        ret += P[i][c];
    }
    return ret;
}

signed main(){
    cin >> N;
    ll f;
    REP(i, N){
        REP(j, 10){
            cin >> f;
            F[i] += f * (1 << j);
        }
    }
    REP(i, N) REP(j, 11) cin >> P[i][j];
    ll ans = LONG_LONG_MIN;
    FOR(i, 1, 1 << 10){
        ans = max(ans, solve(i));
    }
    PRINT(ans);
    return 0;
}