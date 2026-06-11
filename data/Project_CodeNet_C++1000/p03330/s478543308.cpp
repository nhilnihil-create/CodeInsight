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

int n, c;
VVl diff;
Vi clist;

ll dfs(int depth) {
    if (depth == 3) {
        ll res = 0;
        REP(i, 3) {
            res += diff[i][clist[i]];
        }
        return res;
    }
    ll mini = 1e18;
    REP(i, c) {
        if (depth >= 1 && i == clist[depth-1]) continue;
        if (depth >= 2 && i == clist[depth-2]) continue;
        clist[depth] = i;
        mini = min(mini, dfs(depth+1));
    }
    return mini;
}

int main() {
    cin >> n >> c;
    VVl d(c, Vl(c));
    REP(i, c) REP(j, c) cin >> d[i][j];
    VVi x(n, Vi(n));
    REP(i, n) REP(j, n) {
        cin >> x[i][j];
        x[i][j]--;
    }

    diff = VVl(3, Vl(c, 0));
    REP(i, n) REP(j, n) {
        int mod = (i+j+2) % 3;
        int color = x[i][j];
        REP(k, c) {
            diff[mod][k] += d[color][k];
        }
    }

    clist = Vi(3);
    cout << dfs(0) << '\n';

    return 0;
}
