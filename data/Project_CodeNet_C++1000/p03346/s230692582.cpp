#include <cstdio>
#include <algorithm>
using namespace std;

int p[222222];

int main(void)
{
	int n, a, i;

	scanf("%d" ,&n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d" ,&a);
		p[a] = i;
	}

	int change = 1, ans = 1;
	for (i = 1; i <= n; i++)
		if (p[i] < p[i + 1])
			change++;
		else
		{
			ans = max(ans, change);
			change = 1;
		}

	printf("%d" ,n - ans);
	return 0;
}