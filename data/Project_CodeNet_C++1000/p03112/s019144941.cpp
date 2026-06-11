#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;
const LL INF = 1e18;

int n, m, k;
LL a[N], b[N];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i ++ ) scanf("%lld", &b[i]);
	a[0] = b[0] = -INF;
	a[n + 1] = b[m + 1] = INF;
	
	while (k -- )
	{
		LL x;
		scanf("%lld", &x);
		
		LL res = INF;
		LL la = a[upper_bound(a, a + n + 2, x) - a - 1];
		LL lb = b[upper_bound(b, b + m + 2, x) - b - 1];
		LL ra = a[lower_bound(a, a + n + 2, x) - a];
		LL rb = b[lower_bound(b, b + m + 2, x) - b];
		
		res = min(res, max(ra, rb) - x);
		res = min(res, x - min(la, lb));
		res = min(res, 2LL * min(ra - x, x - lb) + max(ra - x, x - lb));
		res = min(res, 2LL * min(rb - x, x - la) + max(rb - x, x - la));
		printf("%lld\n", res);
	}
    return 0;
}