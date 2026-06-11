#include <iostream>
#include <cstdio>
#define MN 20010

typedef long long ll;

ll Min[MN], lazy[MN];

void add(int x, ll v) {lazy[x] += v; Min[x] += v;}
void pushdown(int x)
{
	if(lazy[x]) 
	{
		add(x << 1, lazy[x]);
		add(x << 1 | 1, lazy[x]);
		lazy[x] = 0;
	}
}

void modify(int x, int l, int r, int L, int R, ll v, int t)
{
	if(L > R) return;
	if(l == L && r == R)
	{
		if(t == 0) add(x, v);
		else Min[x] = v;
		return;
	}
	pushdown(x); int mid = l + r >> 1;
	if(R <= mid) modify(x << 1, l, mid, L, R, v, t);
	else if(L > mid) modify(x << 1 | 1, mid + 1, r, L, R, v, t);
	else modify(x << 1, l, mid, L, mid, v, t), modify(x << 1 | 1, mid + 1, r, mid + 1, R, v, t);
	Min[x] = std::min(Min[x << 1], Min[x << 1 | 1]);
}

ll query(int x, int l, int r, int L, int R)
{
	if(l == L && r == R) return Min[x];
	pushdown(x); int mid = l + r >> 1;
	if(R <= mid) return query(x << 1, l, mid, L, R);
	else if(L > mid) return query(x << 1 | 1, mid + 1, r, L, R);
	else return std::min(query(x << 1, l, mid, L, mid), query(x << 1 | 1, mid + 1, r, mid + 1, R));
}

int main()
{
	int n, a, b; 
	scanf("%d%d%d", &n, &a, &b);
	modify(1, 0, n, 0, n, 1e18, 0);
	modify(1, 0, n, 0, 0, 0, 1);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		modify(1, 0, n, x, x, query(1, 0, n, 0, x), 1);
		modify(1, 0, n, 0, x - 1, a, 0);
		modify(1, 0, n, x + 1, n, b, 0);
	}
	printf("%lld\n", query(1, 0, n, 0, n));
}