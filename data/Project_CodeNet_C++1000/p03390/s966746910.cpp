#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
int main()
{
	// freopen("ARC094-D.in", "r", stdin);
	int q; 
	scanf("%d", &q);
	while (q--)
	{
		ll a, b; 
		scanf("%lld%lld", &a, &b); 
		if (a > b)
			std::swap(a, b); 
		ll l = 0, r = 1e9, c; 
		while (l <= r)
		{
			ll m = l + r >> 1; 
			if (m * m <= a * b - 1)
			{
				c = m; 
				l = m + 1; 
			}
			else
				r = m - 1; 
		}
		if (a == b || a + 1 == b)
			printf("%lld\n", a + a - 2);
		else if (c * (c + 1) >= a * b)
			printf("%lld\n", c + c - 2);
		else
			printf("%lld\n", c + c - 1);
	}
	return 0; 
}
