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

struct T {
    int s, t, c;
};

int n, c;

int main() {
    cin >> n >> c;

    V<T> v(n);
    REP(i, n) {
        int s, t, c; cin >> s >> t >> c;
        v[i] = {s, t, c};
    }

    sort(ALL(v), [](const T& a, const T& b) {
        if (a.t == b.t) {
            return a.s < b.s;
        }
        return a.t < b.t;
    });

    V<Pii> res(30, {-1, -1});
    for (auto x: v) {
        int maxi = -1e9, maxidx = -1;
        REP(i, 30) {
            if ((res[i].second == x.c && res[i].first > x.s) ||
                    (res[i].second != x.c && res[i].first >= x.s)) {
                continue;
            }
            if (maxi < res[i].first) {
                maxi = res[i].first;
                maxidx = i;
            }
        }
        res[maxidx] = {x.t, x.c};
    }

    int cnt = 0;
    REP(i, 30) {
        if (res[i] != make_pair(-1, -1)) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}
