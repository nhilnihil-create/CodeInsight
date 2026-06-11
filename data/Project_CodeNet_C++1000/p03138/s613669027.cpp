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

ll n, k;
// string s;

int main() {
    cin >> n >> k;
    Vl a(n);
    REP(i, n) cin >> a[i];

    Vl cnt(40, 0);
    REP(i, n) {
        bitset<40> A(a[i]);
        REP(j, 40) if (A[j]) cnt[j]++;
    }

    bitset<40> K(k+1);
    ll maxi = 0, buf = 0;
    RREP(i, 39, 0) {
        if (!K[i]) {
            buf += cnt[i] * (1LL << i);
            continue;
        }
        ll sum = buf;
        sum += cnt[i] * (1LL << i);
        RREP(j, i-1, 0) {
            sum += max(cnt[j], n - cnt[j]) * (1LL << j);
        }
        maxi = max(maxi, sum);

        buf += (n - cnt[i]) * (1LL << i);
    }
    cout << maxi << '\n';

    return 0;
}
