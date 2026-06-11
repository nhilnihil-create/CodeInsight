#include <bits/stdc++.h>

using namespace std;

#define int 		long long
#define ld			double
#define endl		"\n"
#define mod			1000000007
#define inf			1e12
#define IOS			ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int32_t main() {

	IOS;

	int n;
	cin >> n;

	vector<int> v(4, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[0];
		v[v[0]]++;
	}
	int mx = 302;

	ld dp[mx][mx][mx];

	for (int c = 0; c < mx; c++) {
		for (int b = 0; b < mx; b++) {
			for (int a = 0; a < mx; a++) {
				ld k = a + b + c;
				if (k > mx || k == 0)
					continue;

				if (a) {
					dp[a][b][c] += dp[a - 1][b][c] * a / k;
				}
				if (b) {
					dp[a][b][c] += dp[a + 1][b - 1][c] * b / k;
				}
				if (c) {
					dp[a][b][c] += dp[a][b + 1][c - 1] * c / k;
				}

				dp[a][b][c] += n / k;
			}
		}
	}

	cout << setprecision(12) << dp[v[1]][v[2]][v[3]] << endl;

	return 0;
}