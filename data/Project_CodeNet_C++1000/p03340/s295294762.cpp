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

    VVi bitcnt(n+1, Vi(20, 0));
    REP(i, n) {
        REP(j, 20) {
            if (a[i] & (1 << j)) {
                bitcnt[i+1][j]++;
            }
        }
    }

    ll res = 0;
    int right = 1;
    Vi cnt(20, 0);
    REP2(left, 1, n+1) {
        while (right <= n) {
            bool f = false;
            REP(i, 20) {
                f |= cnt[i] + bitcnt[right][i] > 1;
            }
            if (f) break;
            REP(i, 20) {
                cnt[i] += bitcnt[right][i];
            }
            right++;
        }
        res += right - left;

        REP(i, 20) {
            cnt[i] -= bitcnt[left][i];
        }
    }
    cout << res << '\n';

    return 0;
}
