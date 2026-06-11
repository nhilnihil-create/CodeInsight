#include <algorithm>
#include <cstdio>
#include <vector>
#define pb push_back
std::vector<int> vec[200005];
int main()
{
	// freopen("AGC029-D.in", "r", stdin);
	int h, w, n;
	scanf("%d%d%d", &h, &w, &n);
	while (n--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		vec[y].pb(x);
	}
	for (int i = 1; i <= w; i++)
		std::sort(vec[i].begin(), vec[i].end());
	int x = 1, y = 1, ans = h;
	while (x <= h)
	{
		auto it = std::lower_bound(vec[y].begin(), vec[y].end(), x);
		if (it != vec[y].end())
		{
			ans = std::min(ans, *it - 1);
			if (*it == x + 1)
				break;
		}
		x++;
		if (y != w && !binary_search(vec[y + 1].begin(), vec[y + 1].end(), x))
			y++;
	}
	printf("%d\n", ans);
	return 0;
}
