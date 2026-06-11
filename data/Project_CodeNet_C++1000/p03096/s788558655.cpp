#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define for1(i, n) for(int i = 1; i <= (n);i++)
using namespace std;
int input() {
	int r;
	scanf("%lld", &r);
	return r;
}
int n, c[234567], dp[234567], c1[234567];
signed main() {
	n = input(); for1(i, n)c[i] = input();
	dp[0] = 1;
	for1(i, n) {
		dp[i] = dp[i - 1];
		if (c1[c[i]] > 0 && c[i] != c[i - 1])dp[i] += dp[c1[c[i]]];
		c1[c[i]] = i;
		dp[i] %= mod;
	}
	printf("%lld\n", dp[n]);
}