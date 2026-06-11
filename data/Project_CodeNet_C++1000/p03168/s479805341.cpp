#include <bits/stdc++.h>
using namespace std;

int n;
double dp[3000][3000] ;

double a[3000] = {0.0};
double f(int h, int t, int i) {
	if (dp[h][i] > -0.9)
		return dp[h][i];//if (dp[h][i] != 0) return dp[h][i];
	if (h <= 0 && t <= 0) return 1;
	//if (i > n) return 0;
	double ans = 0;
	if (h)
		ans += a[i] * f(h - 1, t, i + 1);
	if (t)
		ans += (1 - a[i]) * f(h, t - 1, i + 1);
	return dp[h][i] = ans;
}

int main()
{	//c_p_c();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int k = ( n + 1) / 2 ;
	double ans = 0;
	for (int i = k; i <= n; i++) {
		ans += f(i, n - i, 1);
	}
	//cout << ans;
	cout << fixed << setprecision(10) << ans;
	return 0;
}