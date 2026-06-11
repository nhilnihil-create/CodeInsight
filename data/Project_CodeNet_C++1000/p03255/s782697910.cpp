#include <cstdio>
#include <iostream>
 
typedef unsigned long long ull;
int x[201000];
int k, n;
ull b[201000];

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &x[i]), b[i] = b[i - 1] + x[i];
	ull ans = 18446744073709551615ull; //ULLONG_MAX
	for(int i = 1; i <= n; i++)
	{
		ull res = 0; ull s = 1;
		for(int j = n; j >= 1; j -= i, s++)
		{
			if(s == 1) res += (b[j] - b[std::max(0, j - i)]) * 5;
			else res += (b[j] - b[std::max(0, j - i)]) * ((s + 1) * (s + 1) - s * s);
		}
		res += 1ull * i * k;
		ans = std::min(ans, res);
	}
	printf("%llu\n", ans + 1ull * n * k);
	return 0;
}