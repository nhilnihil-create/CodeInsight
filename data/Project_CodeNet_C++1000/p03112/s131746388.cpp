#include <bits/stdc++.h>
#include <bitset>
#include <cassert>
#include <cstring>
#include <functional>
#include <iomanip>
#include <list>
#include <cmath>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <vector>
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
using namespace std;
#define REP(i, n) for (int64_t i = 0; i < (int64_t)n; i++)
#define REP_FOR(i, a, b) for (int64_t i = (int64_t)a; i < (int64_t)b; i++)
#define REP_REV(i, a, b) for (int64_t i = (int64_t)a; i > (int64_t)b; i--)
#define FORALL(v) (v).begin(), (v).end()
#define mp(a, b) make_pair(a, b)
#define eb(x) emplace_back(x)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int64_t, int64_t> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int64_t> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int64_t infi = 1147483600;
const ll infl = 4e18 + 5;
const char EOL = '\n';
//cout << fixed << setprecision(17) << res << endl;
// const ll MOD = 1000000009;

int main() {
    ll a, b, q;
    cin >> a >> b >> q;
    vector<ll> S(a+2, 0), T(b+2, 0);
    for (ll i = 0; i < a; ++i) {
        cin >> S[i+1];
    }
    S[0] = -1e18;
    S[a+1] = 1e18;
    for (ll i = 0; i < b; ++i) {
        cin >> T[i+1];
    }
    T[0] = -1e18;
    T[b+1] = 1e18;

    for (ll i = 0; i < q; ++i) {
        ll p;
        cin >> p;
        auto s1 = upper_bound(S.begin(), S.end(), p);
        auto s2 = s1-1;
        auto t1 = upper_bound(T.begin(), T.end(), p);
        auto t2 = t1-1;

        auto res = min({
            abs(*s1-*t1)+abs(*t1-p),
            abs(*s1-*t1)+abs(*s1-p),
            abs(*s2-*t2)+abs(*t2-p),
            abs(*s2-*t2)+abs(*s2-p),
            abs(*s2-*t1)+abs(*t1-p),
            abs(*s2-*t1)+abs(*s2-p),
            abs(*s1-*t2)+abs(*t2-p),
            abs(*s1-*t2)+abs(*s1-p)
        });
        cout << res << endl;
    }
}
