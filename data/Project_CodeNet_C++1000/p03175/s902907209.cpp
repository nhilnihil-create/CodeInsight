#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b); i >= (a); i--)
#define R0F(i, a) ROF(i, 0, a-1)
#define trav(x, a) for (auto& x: a)

const int MX  = 2e5+5;
const int MOD = 1e9+7;
const ll  INF = 1061109567; // 4557430888798830399LL
const ld  EPS = 1e-9;
const ld  PI  = acos(-1);

int N;
vi adj[MX];
ll dp[2][MX];

void solve_dp(int u, int p) {
    dp[0][u] = dp[1][u] = 1;

    trav(v,adj[u]) if (v != p) {
        solve_dp(v,u);
        dp[0][u] = (dp[0][u]*(dp[0][v]+dp[1][v])%MOD)%MOD;
        dp[1][u] = (dp[1][u]*dp[0][v])%MOD;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    F0R(i,N-1) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].pb(v); adj[v].pb(u);
    }

    solve_dp(0,-1);

    cout << (dp[0][0]+dp[1][0])%MOD << "\n";
}
