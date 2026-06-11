#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5050;
int n, a, b;
int loc[N];
ll f[N][2 * N];
int main() {
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++) {
		int t; scanf("%d", &t); loc[t] = i;
	}
	memset(f, 127, sizeof f);
	memset(f[0], 0, sizeof f[0]);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 2 * n; j++) {
			f[i][j] = f[i - 1][j - (j & 1)];
			if (j < loc[i] * 2) f[i][j] += b;
				else if (j > loc[i] * 2) f[i][j] += a;
			f[i][j] = min(f[i][j - 1], f[i][j]);
		}
	}
	ll ans = 1e18;
	for(int j = 1; j <= 2 * n; j++) ans = min(ans, f[n][j]);
	cout << ans << endl;
}