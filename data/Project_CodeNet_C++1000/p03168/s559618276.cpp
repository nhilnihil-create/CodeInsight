#include <bits/stdc++.h>
using namespace std;

int n;
double dp[3000][3000] ;

double a[3000] = {0.0};
double f(int h,  int i) {

	if (h == 0 ) return 1;
	if (i == n + 1) return 0;
	if (dp[i][h] > -0.9)
		return dp[i][h];

	return dp[i][h] = a[i] * f(h - 1,  i + 1) + (1 - a[i]) * f(h,  i + 1);
}

int main()
{	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int k = ( n + 1) / 2 ;
	double ans = 0;
	// for (int i = k; i <= n; i++) {
	// 	ans +=
	// }
	//cout <<
	cout << fixed << setprecision(10) << f(k,  1);
	return 0;
}