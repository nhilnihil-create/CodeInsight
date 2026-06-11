#include<bits/stdc++.h>
#define maxn 200010
using namespace std;
set<int> S[maxn];
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		S[y].insert(x);
	}
	for (int i = 1; i <= m; i++)
		S[i].insert(n + 1);
	int res = *(S[1].begin());
	int cur_x = 1, cur_y = 1;
	while (true)
	{
		if (S[cur_y].find(cur_x + 1) != S[cur_y].end()) break;
		if (cur_y == m) break;
		cur_x++;
		if (S[cur_y + 1].find(cur_x) != S[cur_y + 1].end()) continue;
		cur_y++;
		res = min(res, *(S[cur_y].upper_bound(cur_x)));
	}
	printf("%d\n", res - 1);
	return 0;
}