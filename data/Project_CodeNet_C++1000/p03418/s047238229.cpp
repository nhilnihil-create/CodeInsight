#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

signed main(){
    ll N, K;
    cin >> N >> K;
    if(K == 0){
        PRINT(N * N);
        return 0;
    }
    ll ans = 0;
    FOR(b, K + 1, N + 1){
        ans += (b - K) * (N / b);
        ans += max(0LL, N % b - K + 1);
    }
    PRINT(ans);
    return 0;
}