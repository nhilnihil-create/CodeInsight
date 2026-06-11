#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

const ll mod = 1'000'000'007;
ll dp[100005][3];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string s; read(s);
	int n = sz(s);
	s = ' ' + s;

	ll qmult = 1;

	rep(i, 1, n + 1) {
		dp[i][0] = dp[i - 1][0], dp[i][1] = dp[i - 1][1], dp[i][2] = dp[i - 1][2];
		if (s[i] == 'A') dp[i][0] += qmult;
		if (s[i] == 'B') (dp[i][1] += dp[i - 1][0]) %= mod;
		if (s[i] == 'C') (dp[i][2] += dp[i - 1][1]) %= mod;
		if (s[i] == '?') {
			dp[i][0] = (dp[i - 1][0] * 3 + qmult) % mod;
			dp[i][1] = (dp[i - 1][1] * 3 + dp[i - 1][0]) % mod;
			dp[i][2] = (dp[i - 1][2] * 3 + dp[i - 1][1]) % mod;
			qmult = qmult * 3 % mod;
		}
		//printf("%d %lld %lld %lld\n", i, dp[i][0], dp[i][1], dp[i][2]);
	}

	die(dp[n][2]);
}
