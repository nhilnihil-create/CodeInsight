#include <bits/stdc++.h>

#define int long long

using namespace std;
const int N = 200000;

int n, lim;
int a[N], sum[N], S[N+10];

void add(int x,int v) {
	for (int i=x;i<=N;i+=(i&-i))
		S[i] += v;
	return;
}

int ask(int x,int cnt) {
	for (int i=x;i>=1;i-=(i&-i))
	    cnt += S[i];
	return cnt;
}

bool check(int x)
{
	sum[0] = 0;
	for (int i=1;i<=n;++i)
		sum[i] = sum[i-1] + (a[i] >= x ? 1 : -1);
	int v = n+1, ans = 0;
	for (int i=1;i<=n;++i)
	{
		ans += ask(sum[i]+v,0);
		add(sum[i]+v,1);
		ans += sum[i] >= 0;
	}
	for (int i=1;i<=n;++i)
		add(sum[i]+v,-1);
	if (lim % 2 == 1) return ans > lim/2;
	if (lim % 2 == 0) return ans >= lim/2;
}

signed main(void)
{
	scanf("%lld", &n);
	for (int i=1;i<=n;++i)
		scanf("%lld", a+i);
	lim = 1LL*n*(n+1)/2;
	int l = 1, r = 1e9, mid;
	while (l+1 < r) {
		mid = l+r >> 1;
		check(mid) ? l = mid : r = mid;
	}
	printf("%lld\n", check(r) ? r : l);
	return 0;
}