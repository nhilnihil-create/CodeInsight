#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 2e5 + 7;
int n, c[maxn], a[maxn], t;
long long now[maxn], dp[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
	for (int i = 1; i <= n; ++i) if(c[i] != c[i - 1]) a[++t] = c[i];
	dp[0] = 1;
	for (int i = 1; i <= t; ++i) {
		dp[i] = (now[a[i]] + dp[i - 1]) % mod;
		now[a[i]] = (now[a[i]] + dp[i - 1]) % mod;
	}
	printf("%lld\n", dp[t]);
	return 0;
}