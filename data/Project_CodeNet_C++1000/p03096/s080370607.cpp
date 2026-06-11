#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 20, mod = 1e9 + 7;
long long n, c[maxn], dp[maxn], p[maxn];

int main () {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	dp[1] = 1;
	p[c[1]] += 1;
	for (int i = 2; i <= n; i++) {
		if (c[i] != c[i - 1]) 
			p[c[i]] = (p[c[i]] + dp[i - 1]) % mod;
		dp[i] = p[c[i]] % mod;
	}
	cout << dp[n];
	return 0;
}