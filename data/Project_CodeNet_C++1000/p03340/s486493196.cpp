#include <bits/stdc++.h>
using namespace std;
int n, s;
int a[200020];
long long z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0, j = 0; i < n; s ^= a[i++])
	{
		while (j < n && (s & a[j]) == 0)
		{
			s ^= a[j++];
		}
		z += j - i;
	}
	printf("%lld\n", z);
	return 0;
}