#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int n, a[3][N], sum[3][N];
int main () {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	//freopen ("Problem_A_Contest_381560_Vjudge.inp", "r", stdin);
	//freopen ("Problem_A_Contest_381560_Vjudge.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]) + a[i][j];
		}
	}
	cout << sum[2][n];
	return 0;
}
