#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 510, M = 1010;

int n, m, k;
int f[N][N];
vector<int> L[N], R[N];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i ++ )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		L[l].push_back(r);
		R[r].push_back(l);
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
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", f[l][r]);
	}
	return 0;
}