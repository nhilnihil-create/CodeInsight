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

int n, k;

int main() {
    cin >> n >> k;
    V<Pll> pos(n);
    REP(i, n) {
        ll x, y; cin >> x >> y;
        pos[i] = {x, y};
    }

    sort(ALL(pos));

    ll result = 5e18;
    REP(i, n) REP2(j, i+k, n+1) {
        V<Pll> v(pos.begin()+i, pos.begin()+j);
        sort(ALL(v), [](const Pll& a, const Pll& b) {
            return a.second < b.second;
        });
        ll mini = 1e18;
        REP(i2, (j-i)-k+1) {
            mini = min(mini, v[i2+k-1].second - v[i2].second);
        }
        result = min(result, mini * (pos[j-1].first - pos[i].first));
    }

    cout << result << '\n';

    return 0;
}
