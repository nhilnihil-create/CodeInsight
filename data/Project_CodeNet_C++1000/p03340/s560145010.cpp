#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

int a[N];
int f[N], s[N];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) 
	{
		f[i] = f[i - 1] ^ a[i];
		s[i] = s[i - 1] + a[i];
	}

	LL ans = 0;
	int L = 1;
	for (int R = 1; R <= n; R++)
	{
		while ((f[R] ^ f[L - 1]) != (s[R] - s[L - 1])) L++;
		ans += R - L + 1;
	}

	printf("%lld\n", ans);

	return 0;
}	
