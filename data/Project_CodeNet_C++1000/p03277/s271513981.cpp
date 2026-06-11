#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
const int MAXN = 100010;
typedef long long ll;

int n, a[MAXN], sum[MAXN];
int tree[MAXN << 1];

void modify(int p, int v)
{
	for(; p < (MAXN << 1); p += lowbit(p))
		tree[p] += v;
}

int query(int p)
{
	int res = 0;
	for(; p; p -= lowbit(p)) res += tree[p];
	return res;
}

bool Check(int mid)
{
	ll res = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] >= mid) sum[i] = sum[i - 1] + 1;
		else sum[i] = sum[i - 1] - 1;
		if(sum[i] >= 0) ++res;
	}
	for(int i = 1; i <= n; ++i) sum[i] += 100001;
	memset(tree, 0, sizeof(tree));
	for(int i = 1; i <= n; ++i)
	{
		res += query(sum[i]);
		modify(sum[i], 1);
	}
	if(res >= (((ll)n * (n + 1) / 2) + 1ll) / 2ll) return 1;
	return 0;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int l = 1, r = 1e9, ans = 0;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(Check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}