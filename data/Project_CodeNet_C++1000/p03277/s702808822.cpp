#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(x) (x & (-x))
const int maxn = 1e5 + 10;
int a[maxn], b[maxn];
int C[maxn * 2];
int n;
void add(int x, int val)
{
	for(int i = x; i < maxn * 2; i += lowbit(i))
		C[i] += val;
}
int query(int x)
{
	int ret = 0;
	for(int i = x; i; i -= lowbit(i))
		ret += C[i];
	return ret;
}
bool check(int x)
{
	memset(C, 0, sizeof C);
	const ll K = 1ll * n * (n + 1) / 4 + 1;
	ll cnt = 0;
	int sum = 0;
	add(sum + maxn, 1);
	for(int i = 1; i <= n; ++i)
	{
		if(a[i] <= x)
			--sum;
		else
			++sum;
		cnt += query(sum + maxn);
		add(sum + maxn, 1);
	}
	cnt = 1ll * n * (n + 1) / 2 - cnt;
	if(cnt >= K)
		return 1;
	else
		return 0;
}		
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int l = 1, r = n;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(b[mid]))
			r = mid - 1;
		else
			l = mid + 1;
	}
	printf("%d\n", b[l]);
	return 0;
}
	 