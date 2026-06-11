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
const ll INF = 1LL<<30;

int main(void) {
    string s;
    cin >> s;
    const ll n = s.size();

    int rui = 0;
    vector<int> dp1(n), dp2(1LL<<26, INF);
    dp1[0] = dp2[0] = 0;
    REP(i, n) {
        rui ^= 1LL<<(s[i]-'a');
        int mi = dp2[rui];
        REP(j, 26) chmin(mi, dp2[rui^(1LL<<j)]);
        dp1[i] = mi + 1;
        chmin(dp2[rui], dp1[i]); 
    }
    cout << dp1[n-1] << endl;

    return 0;
}