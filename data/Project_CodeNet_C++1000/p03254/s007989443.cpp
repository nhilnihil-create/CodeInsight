#include <cstdio>
#include <algorithm>
using namespace std;
int a[101];
int main(void)
{
	int n, x;
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (x < a[i])
		{
			printf("%d", ans);
			return 0;
		}
		++ans;
		x -= a[i];
	}
	if (x) --ans;
	printf("%d\n", ans);
	return 0;
}