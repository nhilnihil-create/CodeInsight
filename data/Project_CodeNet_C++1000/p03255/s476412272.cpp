#include<bits/stdc++.h>
#define maxn 200010
#define ll long long
#define INF 1e18
using namespace std;
int x[maxn], n;
ll pre[maxn];
ll solve(int sum)
{
	ll res = 0;
	int cur = n, now = 1;
	res = 2 * (pre[cur] - pre[cur - sum]);
	while (cur)
	{
		now++;
		int tl = max(1, cur - sum + 1);
		ll delta = (ll)now * now - ((ll)now - 1) * (now - 1);
		if ((INF - res) / (pre[cur] - pre[tl - 1]) < delta) return INF;
		res += delta * (pre[cur] - pre[tl - 1]);
		cur = tl - 1;
	}
	return res;
}
int main()
{
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		pre[i] = pre[i - 1] + x[i];
	}
	ll res = INF;
	for (int i = 1; i <= n; i++)
	{
		ll cur = ((ll)n + i) * m + solve(i);
		res = min(res, cur);
	}
	printf("%lld\n", res);
	return 0;
}