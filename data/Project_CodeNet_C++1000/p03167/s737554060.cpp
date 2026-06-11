#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ar array
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9 + 7;
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;

void solve() {

    ll n, m;
    cin >> n >> m;
    char grid[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    vvi dp(n + 1, vi(m + 1, 0));

    // here dp[i][j] = number of ways to reach (i,j) from (1,1);

    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '#') {
                dp[i][j] = 0;
            } else {
                if (i - 1 > 0)dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if (j - 1 > 0)dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
        }
    }

    cout << dp[n][m] << endl;

}

int32_t main()
{
    IOS
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
