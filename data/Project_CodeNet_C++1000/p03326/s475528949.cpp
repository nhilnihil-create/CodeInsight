#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N, M;
ll x[1010], y[1010], z[1010], sum[1010];

signed main(){
    cin >> N >> M;
    REP(i, N){
        cin >> x[i] >> y[i] >> z[i];
    }
    ll ans = 0;
    ll sgn[3];
    REP(i, 1 << 3){
        REP(j, 3){
            if(i & (1 << j)) sgn[j] = -1;
            else sgn[j] = 1;
        }
        REP(j, N){
            sum[j] = sgn[0] * x[j] + sgn[1] * y[j] + sgn[2] * z[j];
        }
        sort(sum, sum + N, greater<ll>());
        ans = max(ans, accumulate(sum, sum + M, 0LL));
    }
    PRINT(ans);
    return 0;
}