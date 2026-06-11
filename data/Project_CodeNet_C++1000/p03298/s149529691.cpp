#include <bits/stdc++.h>
using namespace std;
const int N = 18 + 2;
long long mask[(1 << N)], dp[N][N], n;
long long ans;
string s, a, b;
void update(int x, int y) {
	if ((int) a.size() >= x + 1 && a[x] == s[x + y]) {
		dp[x + 1][y] += dp[x][y];
	}
	if ((int) b.size() >= y + 1 && b[y] == s[x + y]) {
		dp[x][y + 1] += dp[x][y];
	}
	return;
}
void reset() {
	memset(dp, 0, sizeof(dp));
	a.clear(), b.clear();
	reverse(s.begin(), s.end());
}
long long cal(int x) {
	for (int i = 0; i < n; i++) {
		if ((x >> i) & 1) 
			a += s[i];
		else 
			b += s[i];
	}
//	cout << "a == " << a << " b == " << b << endl;
	reverse(s.begin(), s.end());
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i + j >= n)
				continue;
//			cout << "i = " << i << " j = " << j << " : " << dp[i][j] << endl;
			update(i, j);
		}
	}
	long long rtr = 0;
	for (int i = 0; i <= n; i++) {
//		cout << "i = " << i << " j = " << n - i << " : " << dp[i][n - 1] << endl;
		rtr += dp[i][n - i];
	}
	reset();
	return rtr;
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < (1 << n); i++) {
		ans += cal(i);
	}
	cout << ans;
	return 0;
}