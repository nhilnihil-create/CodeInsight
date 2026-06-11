#include <utility>
#include <cstdio>
#include <set>
int arr[200005];
int main()
{
	// freopen("AGC029-C.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	int l = 1, r = n, ans = -1;
	while (l <= r)
	{
		int m = l + r >> 1;
		std::multiset<std::pair<int, int> > se;
		bool flg = true;
		for (int i = 0; i < n; i++)
		{
			if (se.empty() || (--se.end())->first < arr[i])
			{
				se.insert({arr[i], 0});
				continue;
			}
			while (se.size() >= 2 && (----se.end())->first >= arr[i])
				se.erase(--se.end());
			{
				int val = (--se.end())->second;
				se.erase(--se.end());
				se.insert({arr[i], val});
			}
			auto it = --se.end();
			while (it != se.begin() && it->second == m - 1)
			{
				auto orig = it;
				it--;
				se.insert({orig->first, 0});
				se.erase(orig);
			}
			if (it->second == m - 1)
			{
				flg = false;
				break;
			}
			se.insert({it->first, it->second + 1});
			auto pre = it;
			if ((it != se.begin() && (--pre)->first + 1 == it->first) || (it->first == 1))
			{
				se.erase(it);
				continue;
			}
			{
				se.insert({it->first - 1, it->second});
				se.erase(it);
			}
		}
		if (flg)
		{
			ans = m;
			r = m - 1;
		}
		else
			l = m + 1;
	}
	printf("%d\n", ans);
	return 0;
}
