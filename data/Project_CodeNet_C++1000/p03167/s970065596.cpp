#include <bits/stdc++.h>

#define pb push_back
#define PQ priority_queue
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

typedef long long ll;
typedef long double ld;

//__builtin_popcount(x)

using namespace std;

const int mod = 1e9 + 7;

ll add(ll a, ll b) {
    ll res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

ll sub(ll a, ll b) {
    ll res = a - b + mod;
    if (res >= mod) res -= mod;
    return res;
}

ll mul(ll a, ll b) {
    return (((a % mod) * (b % mod)) % mod);
}

/* Z-FUNCTION
ll l = 0, r = 0, n = (int)s.size();
vector<int> z(n, 0);
for (int i = 1; i < n; i++) {
    if (r >= i) {
        z[i] = min(1ll*z[i-l], r-i+1);
    }
    while (z[i] + i < n && s[z[i]] == s[z[i] + i]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
}
*/

/*vector<int> find_dividers(int x) {
    vector<int> dividers;

    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
           dividers.push_back(i);
            if (i * i != x) {
                dividers.push_back(x / i);
            }
        }
    }

    return dividers;
}*/

/*int nok(int a, int b) {
    return a / __gcd(a, b) * b;
}*/
int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++) {
        if (grid[i][0] == '#') break;
        dp[i][0] = 1;
    }
    for (int j = 1; j < m; j++) {
        if (grid[0][j] == '#') break;
        dp[0][j] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == '#') continue;
            if (grid[i-1][j] != '#' && grid[i][j-1] != '#') {
                dp[i][j] = add(dp[i-1][j], dp[i][j-1]);
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n-1][m-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
