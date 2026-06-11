#include <bits/stdc++.h>
#include <limits>
using namespace std;
using LL = unsigned long long;
int main()
{
	int N, X;
	LL a[200001] = {};
	__int128 sum[200001] = {};

	scanf("%d%d", &N, &X);
	for (int n = 1; n <= N; n++)
		scanf("%llu", &a[n]), sum[n]+=sum[n-1]+a[n];

	__int128 ans = LLONG_MAX;
	for (int r = 1; r <= N; r++)
	{
		__int128 c = (sum[N]-sum[N-r])*2;
		int i;
		for (i = 1; i*r <= N; i++)
			c += (sum[N-i*r+r] - sum[N-i*r]) * (2*i+1);
		c += sum[N-i*r+r] * (2*i+1);
		ans = min(ans, c+(__int128)X*(N+r));
	}
	printf("%llu", (LL)ans);
}