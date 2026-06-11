#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#define MN 101000

typedef long long ll;

struct xxx{
	ll d;
	int id;
}a[MN];

int siz[MN];
std::map<ll, int> mp;
int x[MN], y[MN];

bool cmp(xxx a, xxx b) {return a.d < b.d;}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i].d), a[i].id = i;
	std::sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++) mp[a[i].d] = i, siz[i] = 1;
	ll sum = 0;
	for(int i = n; i >= 2; i--)
	{
		sum += siz[i];
		a[i].d -= n - 2 * siz[i]; 
		if(!mp[a[i].d] || mp[a[i].d] >= i) return 0 * puts("-1");
		siz[mp[a[i].d]] += siz[i];
		x[n - i + 1] = a[i].id; y[n - i + 1] = a[mp[a[i].d]].id; 
	}
	if(sum != a[1].d) return 0 * puts("-1");
	for(int i = 1; i < n; i++) printf("%d %d\n", x[i], y[i]);
}