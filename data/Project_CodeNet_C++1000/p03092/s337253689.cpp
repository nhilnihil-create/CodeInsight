#pragma GCC optimize("O3")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000021
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 5010



int main() {
	long long dp[N];
	long long a[N];
	long long llc[N];
	long long n;
	long long x, y, z, ca, cb;
	scanf("%lld %lld %lld", &n, &ca, &cb);
	f(i, n)scanf("%lld", &a[i]);
	f(i, N)dp[i] = 100000000000000000;
	dp[0] = 0;
	f(i,n) {	
		x = 100000000000000000;
		f(j, a[i]) {
			x = min(x, dp[j]);
		}
		dp[a[i]] = x;
		f(j, a[i])dp[j] += ca;
		for (long long j = a[i] + 1; j <= n; j++) {
			dp[j] += cb;
		}
	}
	x = 100000000000000000;
	f(i, n + 1)x = min(x, dp[i]);
	printf("%lld\n", x);
	return 0;
}