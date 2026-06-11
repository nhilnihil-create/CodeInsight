#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define xx first
#define yy second

const int N = 1e5 + 1;
const int mod = 1e9 + 7;

int add(int x, int y) {
    return ((x + y) % mod + mod) % mod;
}
int mul(ll x, ll y) {
    return (x * y) % mod;
}

int n, memo[2][N];
vector<int> adj[N];

int dp(int j, int i, int par = -1) {
    if (memo[j][i] != -1)
        return memo[j][i];
    int ans = 1;
    for (auto& ch : adj[i]) 
        if (ch != par) {
            int f = 0;
            f = add(f, dp(0, ch, i));
            if (!j)
                f = add(f, dp(1, ch, i));
            ans = mul(ans, f);
        }
    return memo[j][i] = ans;
}

void solve() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < 2; i++)
        fill(memo[i], memo[i] + n, -1);
    int ans = add(dp(0, 0), dp(1, 0));
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int _; cin >> _; while (_--)
    solve();
    return 0;
}
