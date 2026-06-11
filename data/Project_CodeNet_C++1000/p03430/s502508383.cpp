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

ll dp[305][305][305];
int main(void) {
    string s;
    ll m;
    cin >> s >> m;
    ll n = s.size();

    REP(i, n) REP(j, m+1) dp[i][i][j] = 1;
    REP(i, n-1) {
        dp[i][i+1][0] = (s[i]==s[i+1] ? 2 : 1);
        FOR(j, 1, m+1) dp[i][i+1][j] = 2; 
    }

    FOR(w, 1, n+1) REP(l, n-w+1) {
        ll r = l+w-1;
        REP(i, m+1) {
            if(l-1>=0) chmax(dp[l-1][r][i], dp[l][r][i]);
            if(r+1<n) chmax(dp[l][r+1][i], dp[l][r][i]);
            if(l-1>=0 && r+1<n && s[l-1]==s[r+1]) chmax(dp[l-1][r+1][i], dp[l][r][i]+2);
            if(l-1>=0 && r+1<n && i+1<=m) chmax(dp[l-1][r+1][i+1], dp[l][r][i]+2);
        }
    }

    cout << dp[0][n-1][m] << endl;

    return 0;
}