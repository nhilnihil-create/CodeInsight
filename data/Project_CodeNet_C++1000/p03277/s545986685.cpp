#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int  MAXN = 100001;
typedef long long LL;

LL n, a[MAXN], s[MAXN], l, r, f[MAXN * 2 + 10], b[MAXN], c[MAXN * 2 + 10];

void add(LL x)
{
	while (x <= 2 * MAXN) f[x]++, x += x & -x;
}

LL query(LL x)
{
	LL tot = 0;
	while (x > 0) tot += f[x], x -= x & -x;
	return tot;
}

bool check(LL x)
{
	memset(f, 0, sizeof f);
	for (LL i = 1; i <= n; i++)
	{
		if (a[i] >= x) c[i] = 1;
		else c[i] = -1;
		c[i] += c[i - 1];
	}
	LL ans = 0;
	for (LL i = 0; i <= n; i++)
		ans += (query(c[i] + MAXN)), add(c[i] + MAXN);
	return ans >= n * (n + 1) / 4 ? true : false;
}

int main()
{
	cin >> n;
	for (LL i = 1; i <= n; i++) cin >> a[i], s[i] = a[i];
	sort(s + 1, s + n + 1);
	l = 1, r = n; LL mid;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (check(s[mid])) l = mid + 1;
		else r = mid - 1;
	}
	cout << s[r];

	return 0;
}