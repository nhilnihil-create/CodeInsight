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

    bitset<40> K(k);
    VVl dp(41, Vl(2, -1e18));
    dp[40][0] = 0;

    RREP(i, 39, 0) {
        REP(j, 2) {
            REP(bit, j == 1 ? 2 : K[i]+1) {
                int j2 = (j == 1 || bit < K[i]) ? 1 : 0;
                ll sum = dp[i+1][j] + (bit == 0 ? cnt[i] : n-cnt[i]) * (1LL << i);
                dp[i][j2] = max(dp[i][j2], sum);
            }
        }
    }
    cout << max(dp[0][1], dp[0][0]) << '\n';

    return 0;
}
