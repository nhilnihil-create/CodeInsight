#include "bits/stdc++.h"

using namespace std;

using ll = long long;

template<typename T> using V = std::vector<T>;
using Vi = V<int>;
using VVi = V<V<int>>;
using Vl = V<ll>;
using VVl = V<V<ll>>;
using Vs = V<string>;

template<typename T1, typename T2> using P = std::pair<T1, T2>;
using Pii = P<int, int>;
using Pll = P<ll, ll>;
using Pdd = P<double, double>;

template<typename T1, typename T2> using M = std::map<T1, T2>;
using Mii = M<int, int>;
using Mll = M<ll, ll>;
using Msi = M<string, int>;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP2(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define RREP(i,s,e) for(int i=(int)(s);i>=(int)(e);--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin(),ie=(c).end();i!=ie;++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin(),ie=(c).rend();i!=ie;++i)
#define ALL(c) (c).begin(), (c).end()

const double PI = acos(-1);
const ll MOD = 1e9+7;

ll h, w, d, q;

int main() {
    cin >> h >> w >> d;
    M<int, Pii> a;
    REP(i, h) REP(j, w) {
        int x; cin >> x;
        a[x] = {i, j};
    }

    Vl cost(h*w+1, 0);
    REP2(i, d+1, h*w+1) {
        Pii bef = a[i], aft = a[i-d];
        cost[i] = cost[i-d] + abs(bef.first - aft.first) + abs(bef.second - aft.second);
    }

    cin >> q;
    REP(i, q) {
        int l, r;
        cin >> l >> r;
        cout << cost[r] - cost[l] << '\n';
    }

    return 0;
}
