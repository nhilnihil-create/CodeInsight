#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, Z, W, a[3000];

signed main(){
    cin >> N >> Z >> W;
    REP(i, N) cin >> a[i];
    if(N == 1){
        PRINT(abs(a[0] - W));
        return 0;
    }
    PRINT(max(abs(a[N - 2] - a[N - 1]), abs(W - a[N - 1])));
    return 0;
}