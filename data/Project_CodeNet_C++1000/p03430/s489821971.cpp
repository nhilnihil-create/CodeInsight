#include <bits/stdc++.h>
using namespace std;

#ifdef HELTHAZAR
#define dout if (true) cout
#else
#define dout if (false) cout
#endif

#define rep(i, from, to) for (ll i = from; i < ll(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;

const int MAXN = 301;

int used[MAXN][MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];
string s;

int calcdp(int i, int j, int n, int k) {
	if (i > j)
		return 0;
	if (i == j)
		return 1;
	if (used[i][j][k])
		return dp[i][j][k];
	int maxdp = max(calcdp(i + 1, j, n, k), calcdp(i, j - 1, n, k));
	if (s[i] == s[j])
		maxdp = max(maxdp, calcdp(i + 1, j - 1, n, k) + 2);
	else if (k > 0)
		maxdp = max(maxdp, calcdp(i + 1, j - 1, n, k - 1) + 2);
	used[i][j][k] = 1;
	dp[i][j][k] = maxdp;
	return maxdp;
}

void solve() {
	cin >> s;
	int k;
	cin >> k;
	int n = sz(s);
	cout << calcdp(0, n - 1, n, k);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
}
