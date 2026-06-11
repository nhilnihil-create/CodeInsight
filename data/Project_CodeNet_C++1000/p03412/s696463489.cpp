#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG_ 
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];

    ll ret = 0;
    REP(i, 29) {
        vector<ll> va(a), vb(b);
        const ll t = 1LL<<i;
        REP(j, n) {
            va[j] %= t<<1;
            vb[j] %= t<<1;
        }
        sort(ALL(vb));
        ll num = 0;
        REP(j, n) {
            // [t-va[j],2t-va[j]) 
            {
                auto itr1 = lower_bound(ALL(vb), t-va[j]) - vb.begin();
                auto itr2 = lower_bound(ALL(vb), 2*t-va[j]) - vb.begin();
                num += itr2 - itr1;
            }
            // [3t-va[j],4t-va[j])
            {
                auto itr1 = lower_bound(ALL(vb), 3*t-va[j]) - vb.begin();
                auto itr2 = lower_bound(ALL(vb), 4*t-va[j]) - vb.begin();
                num += itr2 - itr1;
            }
        }
        if(num%2) ret |= t;
    }
    cout << ret << endl;

    return 0;
}