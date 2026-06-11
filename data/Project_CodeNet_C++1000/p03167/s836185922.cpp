#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll modl = 1e9 + 7;

void fast() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef tmr
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main() {

	ll n , m;
	cin >> n >> m;

	char grid[n][m];
	for (long i = 0; i < n; i++) {
		for (long j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	ll ans[n][m];
	memset(ans, 0, sizeof ans);


	for (int i = 1; i < m; i++) {
		if (grid[0][i] == '#') break;
		ans[0][i] = 1ll;
	}

	for (int i = 1; i < n; i++) {
		if (grid[i][0] == '#') break;
		ans[i][0] = 1ll;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (grid[i][j] == '#') continue;

			if (j - 1 >= 0) ans[i][j] = ((ans[i][j] + ans[i][j - 1]) % modl);
			if (i - 1 >= 0) ans[i][j] = ((ans[i][j] + ans[i - 1][j]) % modl);
		}
	}

	cout << (ans[n - 1][m - 1] % modl) << endl;
	return 0;

}