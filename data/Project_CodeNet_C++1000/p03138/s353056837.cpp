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

ll gain[42][2];
ll dp[42][2];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; ll k;
	read(n, k);

	rep(i, 0, n) {
		ll t; read(t);
		rep(j, 0, 42) {
			if (t & (1ll << j)) gain[j][0] += 1ll << j;
			else gain[j][1] += 1ll << j;
		}
	}

	rep(i, 0, 42)
		dp[i][0] = dp[i][1] = -0x3f3f3f3f3f3f3f3fll;
	dp[41][1] = 0;
	for (int i = 40; i >= 0; i--) {
		// tight -> tight
		chmax(dp[i][1], dp[i + 1][1] + gain[i][(k >> i) & 1]);
		// tight -> non-tight
		if (k & (1ll << i))
			chmax(dp[i][0], dp[i + 1][1] + gain[i][0]);
		// non-tight -> any
		chmax(dp[i][0], dp[i + 1][0] + max(gain[i][0], gain[i][1]));
		//printf("%2d NT: %20lld T: %20lld G0: %20lld G1: %02lld\n", i, dp[i][0], dp[i][1], gain[i][0], gain[i][1]);
	}

	die(max(dp[0][0], dp[0][1]));
}
