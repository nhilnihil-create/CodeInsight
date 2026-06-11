#include <stdio.h>
typedef long long LL;

LL s(int x, int b)
{
	int t = x / b;
	LL s = (LL)(t - 1) * (LL)t / 2 * (LL)b;
	s += (LL)(x % b + 1) * (LL)t;
	return s;
}

int main() 
{
	int i, n, k, b, y, x;
	LL ss = 0;
	
	scanf("%d%d", &n, &k);
	if(!k){
		printf("%lld\n", (LL)n * (LL)n);
		return 0;
	}
	for(i = k + 1, y = n - k, x = n - i; i <= n; i++, x--){
		ss += s(y, i) - s(x, i) + y - x;
	}
	printf("%lld\n", ss);
			
	return 0;
}