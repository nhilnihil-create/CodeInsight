#include<iostream> 
#include<stdio.h>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<string.h>
#define debug(a)	cout << "*" << a << "*" << endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct	node{
	ll l, r;
}w[3000], h[3000], d[50];

bool cmp1(node a, node b)
{
	return a.l < b.l;
}
bool cmp2(node a, node b)
{
	return a.r < b.r;
}
struct per{
	ll n, s, w, e;
	ll m;
	friend bool operator<(per a, per b)
	{
		return a.m < b.m;
	}
}dot[8000000];
ll n, k, hn, wn, dn, sum;
ll ans;
bool check(per a, node b)
{
	if (a.s <= b.r && b.r <= a.n && a.w <= b.l && b.l <= a.e)
		return true;
	return false;
}
int main()
{
	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &d[i].l, &d[i].r);
	sort(d, d + n, cmp1);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			w[wn].l = d[i].l;
			w[wn].r = d[j].l;
			wn++;
		}
	sort(d, d + n, cmp2);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			h[hn].l = d[i].r;
			h[hn].r = d[j].r;
			hn++;
		}
	for (int i = 0; i < wn; i++)
	{
		for (int j = 0; j < hn; j++)
		{
			dot[dn].n = h[j].r;
			dot[dn].s = h[j].l;
			dot[dn].w = w[i].l;
			dot[dn].e = w[i].r;
			dot[dn].m = (h[j].r - h[j].l) * (w[i].r - w[i].l);
			//printf("%lld %lld %lld %lld %lld\n", dot[dn].n, dot[dn].s, dot[dn].w, dot[dn].e, dot[dn].m); 
			dn++;
		}
	}
	sort(dot, dot + dn);
	for (int i = 0; i < dn; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (check(dot[i], d[j]))
			{
				sum++;
			}
		}
		if (sum >= k)
		{
			ans = dot[i].m;
			break;
		}	
	}
	cout << ans << endl;
}

