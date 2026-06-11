#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7, mxN = 2e5;

int add (int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int mul (ll a, ll b) {
	a *= b;
	if (a >= mod) a %= mod;
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector <int> c(n), a, each(mxN+1);
	for (int i=0; i<n; i++) {
		cin >> c[i];
		if (!i || c[i] != c[i-1]) {
			a.push_back(c[i]);
		}
	}
	n = a.size();
	vector <int> dp(n+1);
	dp[n] = 1;
	for (int i=n-1; i>=0; i--) {
		dp[i] = add(each[a[i]], dp[i+1]);
		each[a[i]] = add(each[a[i]], dp[i+1]);
	}
	cout << dp[0];
	return 0;
}
