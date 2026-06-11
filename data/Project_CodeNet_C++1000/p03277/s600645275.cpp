#include<bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
ll n;
ll A[N];

ll d[N];

ll tree[N * 10], size;
#define lowbit(x) (x) & (-x)
inline void Add(ll p)
{
	while(p <= size)
	{
		++ tree[p];
		p += lowbit(p);
	}
}
inline ll Query(ll p)
{
	ll Ans = 0;
	while(p > 0)
	{
		Ans += tree[p];
		p -= lowbit(p);
	}
	return Ans;
}

inline bool check(ll k)
{
	for(ll i = 1; i <= n; ++ i)
		d[i] = (A[i] >= k) ? 1 : -1;
	for(ll i = 1; i <= n; ++ i)
		d[i] += d[i - 1];
	memset(tree, 0, sizeof(tree));
	size = 2 * N;
	ll Ans = 0;
	for(ll i = 0; i <= n; ++ i)
	{
		Ans += Query(d[i] + N);
		Add(d[i] + N);
	}
	return Ans >= n * (n + 1) / 4;
}
ll L = 0, R = 0;
int main()
{
	scanf("%lld", &n);
	for(ll i = 1; i <= n; ++ i)
		scanf("%lld", &A[i]), R = max(R, A[i]);
	while(L <= R)
	{
		ll mid = (L + R) >> 1;
		if(check(mid))
			L = mid + 1;
		else R = mid - 1;
	}
	printf("%lld", R);
	return 0;
}