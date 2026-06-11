#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
typedef long long ll;

int n, a[MAXN];
ll sum[MAXN];

inline ll ask(int l, int r) {return sum[r] - sum[l - 1];}

pair<int, int> div(int mid)
{
	pair<int, int> ans;
	ll res = 1e18;
	int l = 1, r = mid - 1, pos = 0;
	while(l <= r)
	{
		int i = (l + r) >> 1;
		ll num = abs(ask(1, i) - ask(i + 1, mid));
		if(num < res) res = num, pos = i;
		if(ask(1, i) < ask(i + 1, mid)) l = i + 1;
		else r = i - 1;
	}
	ans.first = pos;
	res = 1e18;
	l = mid + 1, r = n - 1, pos = 0;
	while(l <= r)
	{
		int i = (l + r) >> 1;
		ll num = abs(ask(mid + 1, i) - ask(i + 1, n));
		if(num < res) res = num, pos = i;
		if(ask(mid + 1, i) < ask(i + 1, n)) l = i + 1;
		else r = i - 1;
	}
	ans.second = pos;
	return ans;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
	ll ans = 1e18;
	for(int i = 2; i <= n - 2; ++i)
	{
		pair<int, int> now = div(i);
		ll A = ask(1, now.first);
		ll B = ask(now.first + 1, i);
		ll C = ask(i + 1, now.second);
		ll D = ask(now.second + 1, n);
		ans = min(ans, max(max(A, B), max(C, D)) - min(min(A, B), min(C, D)));
	}
	printf("%lld\n", ans);
	return 0;
}