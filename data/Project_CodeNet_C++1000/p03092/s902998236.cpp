#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll dp[5005][5005], p[5005][5005], n, a, b, loc[5005];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		cin >> p[n-1][i];
		p[n-1][i]--;
	}
	loc[0] = 0;
	for (int i = n-1; i >= 1; --i) {
		int ct = 0;
		for (int j = 0; j < i+1; ++j) {
			if (p[i][j] != i) {
				p[i-1][ct] = p[i][j];
				++ct;
			} else
				loc[i] = j;
		}
		/* for (int j = 0; j < i; ++j)
			cout << p[i-1][j] << ' ';
		cout << endl; */
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i; ++j) {
			//last j guys have free left moves
			if (i == 0) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = (1LL<<60);
			if (loc[i] >= i+1-j) {
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
				dp[i][j] = min(dp[i][j], a + dp[i-1][j-1]);
			}
			else {
				dp[i][j] = min(dp[i][j], dp[i-1][i-loc[i]]+b*(i-j-loc[i]));
				dp[i][j] = min(dp[i][j], a + dp[i-1][j]);
			}
		}
	cout << dp[n-1][0] << endl;
}