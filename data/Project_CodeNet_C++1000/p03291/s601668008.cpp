#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int maxn = 100005;

int add_mod (int a, int b) {
	if (a + b < mod)
		return a + b;
	return a + b - mod;
}

int trips (int a) {
	return add_mod(a, add_mod(a, a));
}

int n, t = 1;
string s;
int dp[maxn][3];

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j)
			dp[i][j] = dp[i - 1][j];
		if (s[i - 1] == 'A')
			dp[i][0] = add_mod(dp[i - 1][0], t);
		else if (s[i - 1] == 'B') 
			dp[i][1] = add_mod(dp[i - 1][1], dp[i - 1][0]);
		else if (s[i - 1] == 'C')
			dp[i][2] = add_mod(dp[i - 1][2], dp[i - 1][1]);
		else {
			dp[i][0] = add_mod(trips(dp[i - 1][0]), t);
			dp[i][1] = add_mod(trips(dp[i - 1][1]), dp[i - 1][0]);
			dp[i][2] = add_mod(trips(dp[i - 1][2]), dp[i - 1][1]);
			t = trips(t);
		}
	}
	cout << dp[n][2] << '\n';
}
