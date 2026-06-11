#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 110, mod = 1e9 + 7;

int n, m, k;
vector<LL> a, b;

int get(vector<LL> &a, int n, LL st)
{
	int l = 0, r = n + 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (a[mid] >= st) r = mid;
		else l = mid + 1;
	}
	return r;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	a.resize(n + 2), b.resize(m + 2);
	for (int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);
	for (int i = 1; i <= m; i ++ ) scanf("%lld", &b[i]);
	a[0] = b[0] = -1e18, a[n + 1] = b[m + 1] = 1e18;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	while (k -- )
	{
		LL x, res = 1e18;
		scanf("%lld", &x);
		int i = get(a, n, x);
		int j = get(b, m, x);
		
		LL ra = a[i] - x;
		LL rb = b[j] - x;
		LL la = x - a[i - 1];
		LL lb = x - b[j - 1];
		
		res = min(res, max(ra, rb));
		res = min(res, max(la, lb));
		res = min(res, la + rb + min(la, rb));
		res = min(res, ra + lb + min(ra, lb));
		printf("%lld\n", res);
	}
	return 0;
}