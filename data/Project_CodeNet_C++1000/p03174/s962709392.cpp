#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

#include <bits/stdc++.h>
using namespace std;

static const ll INF = 1e15;

static const ll mod = 1e9 + 7;

int main() {
	ll n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n, 0));
	rep(i, n) {
		rep(j, n) {
			cin >> grid[i][j];
		}
	}
	vector<vector<ll>> dp(n, vector<ll>(1LL << n, 0));

	for (int i = 0; i < n; i++) {
		if (grid[0][i]) {
			dp[0][1LL << i] = 1;
		}
	}
	for (int i = 1; i < n; i++) {
		for (ll state = 0; state < 1LL << n; state++) {
			if (__builtin_popcountll(state) != i ) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (state & (1LL << j)) continue;
				if (grid[i][j]) {
					(dp[i][(1LL << j) | state] += dp[i - 1][state]) %= mod;
				}
			}
		}
	}
	cout << dp[n - 1][(1LL << n) - 1] << endl;
	return 0;
}
	