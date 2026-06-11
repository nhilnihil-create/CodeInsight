#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define printWithPrecision(x) cout << fixed << setprecision(10) << x << endl;
double dp[3001][3001];

double solve(vector<double>& v, ll i, ll x) {
	if (x == 0) return 1;
	if (i == 0) return 0;
	if (dp[i][x] > -0.9) return dp[i][x];
	return dp[i][x] = (v[i] * solve(v, i - 1, x - 1)) + (((double)1 - v[i]) * solve(v, i - 1, x));
}

void fast() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

}

int main() {
	fast();
	ll n;
	cin >> n;
	memset(dp, -1, sizeof dp);

	vector<double> v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];

	printWithPrecision(solve(v, n, (n + 1) / 2ll));
	return 0;
}

