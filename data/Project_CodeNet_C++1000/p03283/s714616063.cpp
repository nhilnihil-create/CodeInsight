#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510, M = 200010, INF = 0x3f3f3f3f;

int n, m, k;
int f[N][N];
vector<int> L[N], R[N];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i ++ )
	{
		int a, b;
		scanf("%d%d", &a, &b);
		L[a].push_back(b);
		R[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i ++ )
	{
		sort(L[i].begin(), L[i].end());
		sort(R[i].begin(), R[i].end());
	}
	
	for (int len = 1; len <= n; len ++ )
		for (int l = 1; l + len - 1 <= n; l ++ )
		{
			int r = l + len - 1;
			if (r - 1 >= l + 1) f[l][r] += f[l + 1][r - 1];
			
			int i = lower_bound(L[l].begin(), L[l].end(), r) - L[l].begin();
			f[l][r] += i;
			int j = upper_bound(R[r].begin(), R[r].end(), l) - R[r].begin();
			f[l][r] += (int)R[r].size() - j;
			i = lower_bound(L[l].begin(), L[l].end(), r) - L[l].begin();
			j = upper_bound(L[l].begin(), L[l].end(), r) - L[l].begin();
			f[l][r] += j - i;
		}
	
	while (k -- )
	{
		int p, q;
		scanf("%d%d", &p, &q);
		printf("%d\n", f[p][q]);
	}
	return 0;
}