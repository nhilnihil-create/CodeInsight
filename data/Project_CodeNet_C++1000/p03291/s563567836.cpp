#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

ll dp[100001][4] = { { 0 } };

void solve_abc104() {
	string S;
	ll ans = 0;

	cin >> S;

	dp[0][0] = 1;
	rep(i, S.size()) {
		rep(j, 4) {
			if (S[i] == '?') {
				dp[i + 1][j] += 3 * dp[i][j];
			}
			else {
				dp[i + 1][j] += dp[i][j];
			}
			dp[i + 1][j] %= MOD;
		}

		if (S[i] == 'A' || S[i] == '?') {
			dp[i + 1][1] += dp[i][0];
		}
		
		if (S[i] == 'B' || S[i] == '?') {
			dp[i + 1][2] += dp[i][1];
		}
		
		if (S[i] == 'C' || S[i] == '?') {
			dp[i + 1][3] += dp[i][2];
		}

		rep(j, 4) {
			dp[i + 1][j] %= MOD;
		}
	}

	ans = dp[S.size()][3];

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc104();

	return 0;
}