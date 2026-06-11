#include <cstdio>
#include <algorithm>
#include <cstring> 

using namespace std;

int a[10100], lst[10100], cnt[10100], b[10100];
struct xxx{int id, x;}d[10100];

bool cmp(xxx a, xxx b) {return a.x < b.x;}

int main()
{
	int n, k, q; scanf("%d%d%d", &n, &k, &q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]); b[i] = a[i];
		d[i].id = i; d[i].x = a[i];
	}
	sort(d + 1, d + n + 1, cmp);
	sort(a + 1, a + n + 1); int N = unique(a + 1, a + n + 1) - a - 1;
	int ans = 2e9;
	for(int i = 0; i <= N; i++)
	{
		memset(cnt, 0, sizeof(cnt));
		for(int j = 1; j <= n; j++)
		{
			if(b[j] <= a[i]) lst[j] = j;
			else lst[j] = lst[j - 1];
			if(lst[j] != j) cnt[lst[j]]++;
		}
		int o = 0, Max = 0;
		for(int j = 1; j <= n; j++)
		{
			if(d[j].x > a[i] && cnt[lst[d[j].id]] - k + 1 > 0)
			{
				cnt[lst[d[j].id]]--;
				Max = max(Max, d[j].x);
				o++;
				if(o == q) break;
			}
		}
		if(o == q) ans = min(ans, Max - a[i + 1]);
	}
	printf("%d\n", ans);
	return 0;
}