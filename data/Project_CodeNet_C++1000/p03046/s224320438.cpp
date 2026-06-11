#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main()
{
	scanf("%d%d", &m, &k);
	if(m == 0)
	{
		if(k == 0)
			puts("0 0");
		else
			puts("-1");
		return 0;
	}
	if(m == 1)
	{
		if(k == 0)
			puts("0 0 1 1");
		else
			puts("-1");
		return 0;
	}
	n = (1 << m);
	if(k >= n)
	{
		puts("-1");
		return 0;
	}
	for(int i = 0; i < n; ++i)
		if(i != k)
			printf("%d ", i);
	printf("%d ", k);
	for(int i = n - 1; ~i; --i)
		if(i != k)
			printf("%d ", i);
	printf("%d\n", k);
	return 0;
}