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
using Msi = M<string, int>;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP2(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define RREP(i,s,e) for(int i=(int)(s);i>=(int)(e);--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin(),ie=(c).end();i!=ie;++i)
#define ALL(c) (c).begin(), (c).end()

const double PI = acos(-1);
const ll MOD = 1e9+7;

int n, k;

int main() {
    cin >> n >> k;
    V<Pll> v(n);
    REP(i, n) {
        ll t, d; cin >> t >> d;
        v[i] = {d, t};
    }

    sort(ALL(v), greater<Pll>());

    ll D = 0, T = 0;
    M<ll, Pll> m;
    V<Pll> dup;
    REP(i, k) {
        ll d = v[i].first, t = v[i].second;
        if (m.count(t) == 0) {
            m[t] = v[i];
            T++;
        } else {
            dup.push_back(v[i]);
        }
        D += d;
    }
    sort(ALL(dup), greater<Pll>());

    ll maxi = T*T + D;

    REP2(i, k, n) {
        if (dup.empty()) break;
        if (m.count(v[i].second) != 0) continue;
        Pll mini = dup.back();
        dup.pop_back();
        m[v[i].second] = v[i];
        T++;
        D -= mini.first - v[i].first;
        maxi = max(maxi, T*T + D);
    }
    cout << maxi << '\n';

    return 0;
}
