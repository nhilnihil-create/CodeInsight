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
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (auto & a : A) cin >> a;

    ll res = 0;

    for (int d = 60; d >= -1; --d) {
        if (d != -1 && !(k & (1LL<<d))) continue;
        ll tmp = 0;
        for (int e = 60; e >= 0; --e) {
            ll mask = 1LL<<e;
            ll num = 0;
            for (ll i = 0; i < n; ++i) {
                if (A[i] & mask) ++num;
            }
            if (e > d) {
                if (k & mask) {
                    tmp += mask * (n - num);
                } else {
                    tmp += mask * num;
                }
            }
            else if (e == d) {
                tmp += mask * num;
            }
            else {
                tmp += mask * max (num, n - num);
            }
        }
        res = max(res, tmp);
    }

    cout << res << endl;
}
