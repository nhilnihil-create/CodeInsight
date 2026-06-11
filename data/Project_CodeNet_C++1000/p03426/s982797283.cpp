#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll H, W, D;
pll A[100010];
ll acc[100010];

signed main(){
    cin >> H >> W >> D;
    ll a;
    REP(i, H){
        REP(j, W){
            cin >> a;
            A[a] = pll(i, j);
        }
    }
    REP(i, D){
        ll x = i + 1;
        while(x + D <= H * W){
            acc[x + D] = acc[x] + abs(A[x + D].first - A[x].first) + abs(A[x + D].second - A[x].second);
            x += D;
        }
    }
    ll Q, L, R;
    cin >> Q;
    REP(i, Q){
        cin >> L >> R;
        PRINT(acc[R] - acc[L]);
    }
    return 0;
}