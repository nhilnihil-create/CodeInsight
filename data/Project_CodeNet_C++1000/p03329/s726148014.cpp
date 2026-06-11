#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, op[100010];

signed main(){
    cin >> N;
    REP(i, N + 1) op[i] = i;
    op[0] = 0;
    REP(i, N){
        ll j = 6;
        while(i + j <= N){
            op[i + j] = min(op[i + j], op[i] + 1);
            j *= 6;
        }
        j = 9;
        while(i + j <= N){
            op[i + j] = min(op[i + j], op[i] + 1);
            j *= 9;
        }
    }
    PRINT(op[N]);
    return 0;
}