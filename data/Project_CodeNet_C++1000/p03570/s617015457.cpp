#include <cstdio>
#include <cstring>
#include <iostream>

int now, ans, sum[1 << 26], tot;

int main()
{
	char ch = getchar();
	memset(sum, 0x3f, sizeof sum);
	sum[0] = 0;
	while (ch >= 'a' && ch <= 'z')
	{
		now ^= 1 << (ch - 97);
		ans = sum[now];
		for (int i = 0; i < 26; ++i)
			ans = std::min(ans, sum[now ^ (1 << i)]);
		++ans;
		sum[now] = std::min(sum[now], ans);
		ch = getchar();
	}
	printf("%d\n", ans);
	return 0;
}