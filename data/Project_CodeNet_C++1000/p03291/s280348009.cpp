#ifdef _DEBUG
#include "MyLib.h"
#else
#define main_D main
#include "bits/stdc++.h" 
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>
#define FOR(i,s,e) for (int i = int(s); i < int(e); ++i)
#define REP(i,e) FOR(i,0,e)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define LINF (LLONG_MAX/2)
const int MGN = 8;
const int ARY_SZ_MAX = 10000000;
using namespace std;
using ll = long long; using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using vb = vector<bool>; using vvb = vector<vb>; using vvvb = vector<vvb>;
using vl = vector<ll>; using vvl = vector<vl>;
using vd = vector<double>; using vs = vector<string>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using psi = pair<string, int>;
// functions

#endif


int main_D() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S; cin >> S;
    int N = S.size();
    S = "#" + S;

    const ll MOD = 1e9 + 7;

    vvl dp(N + MGN, vl(4, 0));
    dp[0][0] = 1;
    FOR(i,1,N+1) {
        REP(j,4) {
            if (S[i] == '?') dp[i][j] += dp[i-1][j] * 3 % MOD;
            else dp[i][j] += dp[i-1][j] % MOD;
        }

        if (S[i] == 'A' || S[i] == '?') dp[i][1] += dp[i-1][0] % MOD;
        if (S[i] == 'B' || S[i] == '?') dp[i][2] += dp[i-1][1] % MOD;
        if (S[i] == 'C' || S[i] == '?') dp[i][3] += dp[i-1][2] % MOD;
    }

    ll ans = dp[N][3] % MOD;
    cout << ans << endl;

    return 0;
}