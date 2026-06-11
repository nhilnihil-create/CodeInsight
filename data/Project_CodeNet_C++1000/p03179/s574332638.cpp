#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
int N;
string S;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N >> S;
	vector<vector<ll>> dp(N + 1, vector<ll> (N + 1, 0));
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		vector<ll> pre(i, 0);
		for (int j = 1; j < i; j++) {
			pre[j] = (pre[j - 1] + dp[i - 1][j]);
			if (pre[j] >= mod)
				pre[j] -= mod;
		}
		for (int j = 1; j <= i; j++) {
			int l, r;
			if (S[i - 2] == '<') {
				l = 1, r = j - 1;
			} else {
				l = j, r = i - 1;
			}
			if (l <= r) {
				dp[i][j] = (pre[r] - pre[l - 1] + mod);
				if (dp[i][j] >= mod)
					dp[i][j] -= mod;
			}
		}
	}
	ll answer = 0;
	for (int i = 1; i <= N; i++) {
		answer += dp[N][i];
		if (answer >= mod)
			answer -= mod;
	}
	cout << answer;

	return 0;
}