#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<set>
using namespace std;
typedef long long ll;
int main()
{
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		if (a > b)swap(a, b);
		if (a == b || a + 1 == b)printf("%lld\n", a + a - 2);
		else
		{
			ll beg = 0, end = 1010101010LL;
			for (;;)
			{
				if (beg == end)break;
				ll med = (beg + end + 1) / 2;
				if (med*med >= a*b)end = med - 1;
				else beg = med;
			}
			if (beg*(beg + 1) < a*b)printf("%lld\n", beg + beg - 1);
			else printf("%lld\n", beg + beg - 2);
		}
	}
}
