#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define Mod 1000000007

int n, Dp[N], Last[N];

int main()
{
	scanf("%d", &n);
	Dp[0] = 1;
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		Dp[i] = Dp[i - 1];
		if (Last[x] && Last[x] != i - 1)
			Dp[i] = (Dp[i] + Dp[Last[x]]) % Mod;
		Last[x] = i;
	}
	printf("%d\n", Dp[n]);
	return 0;
}