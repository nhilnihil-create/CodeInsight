#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ENDL '\n'
#define all(a) begin(a), end(a)
#define sz(a) (int)(a.size())
#define deb(a) cout << #a << ": " << a << ENDL
#define fore(i, a, b) for(int i(a), ThkMk(b); i < ThkMk; ++i)
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;

const int MAX = 1e5 + 5;

lli MOD = 1e9 + 7;

int main()
{   _

    lli n, k; cin >> n >> k;
    vi v(n); fore(i, 0, n) cin >> v[i];
    reverse(all(v));
    vector<vector<lli>> dp(n, vector<lli>(MAX, 0));
    fore(i, 0, v[0] + 1) dp[0][i] = 1;
    fore(i, 1, n) {
        lli acum = 0;
        fore(j, 0, MAX) {
            acum = (acum + dp[i - 1][j]) % MOD;
            if(j >= v[i] + 1) acum = (MOD + acum - dp[i -1][j - v[i] - 1]) % MOD;
            dp[i][j] = acum;
        }
    }
    cout << dp[n - 1][k] << ENDL;
    return 0;
}
