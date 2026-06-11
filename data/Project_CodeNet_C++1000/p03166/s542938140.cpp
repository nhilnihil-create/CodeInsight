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
vector<vector<int>> g;
vector<int> dp;

int dfs(int u, int p = -1) {
    if (dp[u] != -1) return dp[u];
    int len = 0;
    for (int i = 0; i < (int)g[u].size(); i++) {
        int to = g[u][i];
        if (to != p) {
            len = max(len, 1 + dfs(to, u));
        }
    }

    return dp[u]=len;
}

void solve() {
    cin >> n >> m;
    g.resize(n+1);
    dp.resize(n+1, -1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
    }

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        int x = dfs(i);
        ans = max(ans, x);
    }

    cout << ans << endl;
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
