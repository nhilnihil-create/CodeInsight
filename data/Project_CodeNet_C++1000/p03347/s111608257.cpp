#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n;
ll ans;
int a[maxn];
void no()
{
	puts("-1");
	exit(0);
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	if(a[n] >= n) no();
	ans += a[n];
	int pre = n - a[n];
	for(int i = n - 1; i; --i)
	{
		if(a[i] >= i) no();
		if(i - a[i] > pre) no();
		else if(i - a[i] < pre)
		{
			ans += a[i];
			pre = i - a[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}
		