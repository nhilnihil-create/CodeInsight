#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1E3 + 2;
long long ans[MAXN][MAXN];
const int mode = 1e9 + 7;

int main () {
	int n, m;
	cin >> n >> m;
	// set -1 (to make difference between feeled and not feeled
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			ans[i][j] = -1;
			
	// input of tabel
	string s;
	for (int i = 1; i <= n; i ++) {
		cin >> s;
		for (int j = 1; j <= m; j ++) {
			if (s[j - 1] == '#')
				ans[i][j] = 0;
		}
	}
	// dp calculation
	ans[1][1] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			if (ans[i][j] == -1) {
				ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
				ans[i][j] %= mode;
			}
		}
	cout << ans[n][m] << endl;
	return 0;
}
