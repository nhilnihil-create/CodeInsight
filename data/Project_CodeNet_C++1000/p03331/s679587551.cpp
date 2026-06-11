#include <bits/stdc++.h>
using namespace std;
int f(int x) { return x <= 9 ? x : f(x / 10) + x % 10;}
int main()
{
	int n;
	int ans = -1;
	scanf("%d", &n);
	for(int i = 1; i <= n - i; ++i)
	{
		int ret = f(i) + f(n - i);
		ans = i == 1 ? ret : min(ans, ret);
	}
	printf("%d\n", ans);
	return 0;
}