#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ENDL '\n'
#define all(a) begin(a),end(a)
#define sz(a) (int)(a.size())
#define deb(a) cout << #a << ": " << a << ENDL
#define fore(i, a, b) for(int i(a), ThkMk(b); i < ThkMk; ++i)
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;

lli INF = 1e18;

int main()
{   _
    lli n; cin >> n;
    vi v(n); fore(i, 0, n) cin >> v[i];
    vector<vector<lli>> dp(n, vector<lli>(n, INF));
    fore(i, 0, n) dp[0][i] = 0;
    vector<lli> acum(n + 1, 0);
    fore(i, 1, n + 1) acum[i] = acum[i - 1] + v[i - 1];
    fore(i, 1, n) {
        fore(j, 0, n - i) {
            lli range = acum[j + i  + 1] - acum[j];
            fore(k, 0, i) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k - 1][j + k + 1] + range);
            }
        }
    }
    cout << dp[n - 1][0] << ENDL;
    return 0;
}
