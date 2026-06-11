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
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VVS = vector<VS>;
using VI = vector<int>;
using VVI = vector<VI>;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const ll MOD = 1e+9 + 7;
// --------------------------------------------------------


const int MAX_N = 3e+3;
VVI dp(MAX_N + 1, VI(MAX_N + 1, 0));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    string S; cin >> S;
    string T; cin >> T;

    int N = SZ(S);
    int M = SZ(T);
    S = ' ' + S;
    T = ' ' + T;
    FOR(i, 1, N + 1) FOR(j, 1, M + 1) {
        if (S[i] == T[j]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    // LCS 復元
    int len = dp[N][M], i = N, j = M;
    string ans = string(len, ' ');
    while (len > 0) {
        if (S[i] == T[j]) {
            ans[--len] = S[i];
            i--; j--;
        } else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            j--;
        }
    }
    cout << ans << '\n';

    return 0;
}
