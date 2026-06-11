#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

namespace zyt
{
	const int N = 1010, B = 31;
	const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
	const char ch[] = "RLUD";
	int n, cnt[2];
	pair<int, int> arr[N];
	int abs(const int x)
	{
		return x < 0 ? -x : x;
	}
	bool check(const int x, const int y, const int i)
	{
		return (long long)abs(x) + abs(y) < (1 << i);
	}
	int work()
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &arr[i].first, &arr[i].second), ++cnt[(arr[i].first + arr[i].second) & 1];
		if (cnt[0] && cnt[1])
		{
			 puts("-1");
			 return 0;
		}
		printf("%d\n", cnt[0] ? B + 1 : B);
		if (cnt[0])
		{
			printf("1 ");
			for (int i = 1; i <= n; i++)
				--arr[i].first;
		}
		for (int i = 0; i < B; i++)
			printf("%d ", (1 << i));
		puts("");
		for (int i = 1; i <= n; i++)
		{
			char buf[B + 1];
			buf[B] = '\0';
			int x = arr[i].first, y = arr[i].second;
			for (int j = B - 1; j >= 0; j--)
			{
				for (int k = 0; k < 4; k++)
				{
					if (check(x + dx[k] * (1 << j), y + dy[k] * (1 << j), j))
					{
						buf[j] = ch[k ^ 1];
						x = x + dx[k] * (1 << j), y = y + dy[k] * (1 << j);
						break;
					}
				}
			}
			if (x || y)
			{
				fprintf(stderr, "gg");
				return -1;
			}
			if (cnt[0])
				putchar('R');
			printf("%s\n", buf);
		}
		return 0;
	}
}
int main()
{
	return zyt::work();
}