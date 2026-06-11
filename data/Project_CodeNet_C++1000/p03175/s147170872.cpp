#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

const ll MX = 2e5 + 5;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

#define F0R(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define re(x) cin >> x
#define ps(x) cout << x << "\n";
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x), end(x)
#define sz(x) (ll)x.size()
#define len(x) (ll)x.length()
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {	
		ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); 
		// throws exception when do smth illegal2
		// ex. try to read letter llo ll
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
} 

ll N;
ll dp[MX][2];
vi adj[MX];

void dfs(ll at, ll par) {
	dp[at][0] = dp[at][1] = 1;
	for (auto x: adj[at]) if (x != par) {
		dfs(x, at);
		dp[at][1] = (dp[at][1] * ((dp[x][1] + dp[x][0]) % MOD)) % MOD; 
		dp[at][0] = (dp[at][0] * dp[x][1]) % MOD;
	}
}

int main() {
	cin >> N;
	F0R(i, N - 1) {
		ll u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1, 0);
	ps((dp[1][0] + dp[1][1]) % MOD);
}	






