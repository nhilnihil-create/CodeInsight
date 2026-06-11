#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int ans = 1e9;
int h, w, n;
vector<int> E[maxn];
int main()
{
	scanf("%d%d%d", &h, &w, &n);
	for(int i = 1; i <= n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		E[y].push_back(x);
	}
	int cur = 0, last = h;
	for(int i = 1; i <= w; ++i)
	{
		sort(E[i].begin(), E[i].end());
		++cur;
		for(auto v : E[i])
		{
			if(v < cur) continue;
			else if(v == cur) ++cur;
			else 
			{
				last = min(last, v - 1);
				break;
			}
		}
		if(cur > last) break;
		ans = last;
	}
	printf("%d\n", ans);
	return 0;
}