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

int n, m;
// string s;

int main() {
    cin >> n >> m;
    Vi a(m);
    REP(i, m) cin >> a[i];

    Vi need = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    auto func = [](string &l, string &r) {
        if (l.size() == r.size()) return l < r;
        return l.size() < r.size();
    };

    V<Vs> dp(n+1, Vs(m, "x"));
    REP(i, m) dp[0][i] = "";
    REP2(i, 1, n+1) {
        REP(j, m) {
            if (i < need[a[j]]) continue;
            Vs v;
            REP(k, m) {
                string s = dp[i-need[a[j]]][k];
                if (s == "x") continue;
                string t = s.insert(
                    lower_bound(ALL(s), '0' + a[j], greater<char>()) - s.begin(),
                    to_string(a[j])
                );
                v.push_back(t);
            }
            if (v.empty()) continue;
            sort(ALL(v), func);
            dp[i][j] = v.back();
        }
    }
    Vs res;
    for (auto x: dp[n]) {
        if (x != "x") res.push_back(x);
    }
    cout << *max_element(ALL(res), func) << '\n';

    return 0;
}
