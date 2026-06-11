#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
#define FOR(i,l,r) for (int i = (l); i < (r); ++i)
#define REP(i,n) FOR(i,0,n)
#define SORT(c) sort((c).begin(), (c).end())
#define RSORT(c) sort((c).rbegin(), (c).rend())
#define SZ(c) ((int)(c).size())
#define debug(x) cerr << #x << " = " << (x) << '\n';
using P = pair<int,int>;
using VS = vector<string>;
using VI = vector<int>;
using VVI = vector<VI>;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const ll MOD = 1e+9 + 7;
// --------------------------------------------------------


const int MAX_N = 1e+5;
VVI dp(MAX_N, VI(3, 0));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N; cin >> N;
    VI a(N), b(N), c(N); REP(i,N) cin >> a[i] >> b[i] >> c[i];

    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    FOR(i, 1, N) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
        dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i];
    }

    int ans = max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2]));
    cout << ans << '\n';

    return 0;
}
