#include <bits/stdc++.h>
#define MAX_N 200000
#define mid ((l+r)>>1)
using namespace std;
int n, a[MAX_N+5];
bool chk(int x)
{
	map <int, int> c;
	if (x == 1) return is_sorted(a+1, a+n+1);
	for (int i = 1, v; i <= n; i++)
		if ((v = a[i]) <= a[i-1])
		{
			c[v]++, c.erase(c.upper_bound(v), c.end());
			while (v && c[v] == x) c.erase(v), c[--v]++;
			if (!v) return false;
		}
	return true;
}
int bi_search(int l, int r)
{
	int ret = n;
	while (l <= r)
		if (!chk(mid)) l = mid+1;
		else ret = mid, r = mid-1;
	return ret;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	return printf("%d\n", bi_search(1, n)), 0;
}