#include <bits/stdc++.h>
using namespace std;

int n, m, ct, val[40];
bool s;
char ans[40000];
long long get_dis(pair <int, int> x, pair <int, int> y)
{
	return (long long) abs(x.first - y.first) + abs(x.second - y.second);
}
int main()
{
	m = 32;
	val[1] = 1;
	for (int i = 2; i <= m; i++)
		val[i] = 1 << (i - 2);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		pair <int, int> now, goal, to;
		scanf("%d%d", &goal.first, &goal.second);
		if (i == 1) s = (goal.first + goal.second) & 1;
		else if (s != ((goal.first + goal.second) & 1))
		{
			puts("-1");
			return 0;
		}
		for (int j = m; j >= (s ? 2 : 1); j--)
		{
			char ch;
			long long mini = 0x3f3f3f3f3f3f3f3fLL, tmp;
			if (mini > (tmp = get_dis(goal, make_pair(now.first, now.second + val[j])))) ch = 'U', mini = tmp, to = make_pair(now.first, now.second + val[j]);
			if (mini > (tmp = get_dis(goal, make_pair(now.first, now.second - val[j])))) ch = 'D', mini = tmp, to = make_pair(now.first, now.second - val[j]);
			if (mini > (tmp = get_dis(goal, make_pair(now.first + val[j], now.second)))) ch = 'R', mini = tmp, to = make_pair(now.first + val[j], now.second);
			if (mini > (tmp = get_dis(goal, make_pair(now.first - val[j], now.second)))) ch = 'L', mini = tmp, to = make_pair(now.first - val[j], now.second);
			now = to;
			ans[++ct] = ch;
		}
		ans[++ct] = '\n';
	}
	printf("%d\n", m - s);
	for (int i = m; i >= (s ? 2 : 1); i--)
		printf("%d ", val[i]);
	puts("");
	for (int i = 1; i <= ct; i++)
		putchar(ans[i]);
	return 0;
}