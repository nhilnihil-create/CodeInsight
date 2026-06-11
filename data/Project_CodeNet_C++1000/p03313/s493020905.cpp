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
    vector<ll> a(1LL<<n);
    REP(i, 1LL<<n) cin >> a[i];    

    auto merge = [](PII x, PII y) {
        vector<ll> v({x.first, x.second, y.first, y.second});
        sort(ALL(v));
        return PII(v[3], v[2]);
    };

    vector<PII> dp(1LL<<n);
    REP(i, 1LL<<n) dp[i].first = a[i];
    REP(i, n) REP(j, 1LL<<n) if(j&(1LL<<i)) dp[j] = merge(dp[j], dp[j^(1LL<<i)]);

    ll ma = 0;
    FOR(i, 1, 1LL<<n) {
        chmax(ma, dp[i].first+dp[i].second);
        cout << ma << "\n";
    }
    cout << flush;

    return 0;
}