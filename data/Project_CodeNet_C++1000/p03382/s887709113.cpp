#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, a[maxn], val, mindiff = 1e9 + 10;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int Max = *max_element(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] == Max) continue;
		if(abs(Max / 2 - a[i]) < mindiff)
		{
			mindiff = abs(Max / 2 - a[i]);
			val = a[i];
		}
	}
	printf("%d %d\n", Max, val);
	return 0;
}