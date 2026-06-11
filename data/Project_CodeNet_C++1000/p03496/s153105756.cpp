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

int n;

int main() {
    cin >> n;

    Vi a(n);
    REP(i, n) cin >> a[i];
    auto mini = min_element(ALL(a));
    auto maxi = max_element(ALL(a));

    if (*mini == *maxi) {
        cout << 0 << '\n';
        return 0;
    }
    cout << n*2-1 << '\n';
    if (abs(*mini) < abs(*maxi)) {
        int idx = maxi - a.begin();
        REP(i, n) printf("%d %d\n", idx+1, i+1);
        REP(i, n-1) printf("%d %d\n", i+1, i+2);
    } else {
        int idx = mini - a.begin();
        REP(i, n) printf("%d %d\n", idx+1, i+1);
        RREP(i, n-2, 0) printf("%d %d\n", i+2, i+1);
    }

    return 0;
}
