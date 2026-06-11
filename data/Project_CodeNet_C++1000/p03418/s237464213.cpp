#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(LL i = 0; i < (LL)(n); i++)
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

int main() {
    LL N, K;
    cin >> N >> K;
    LL res = 0;
    FOR(b, 1, N + 1) {
        LL x = max<LL>(0, b - K);
        LL r = max<LL>(0, N%b - K + 1);
        LL p = N/b;
        LL y = x*p + r;
        if(K == 0) {
            y--;
        }
        res += y;
    }
    cout << res << endl;
    return 0;
}
