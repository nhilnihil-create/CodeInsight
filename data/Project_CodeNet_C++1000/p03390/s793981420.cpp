#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


typedef long long i64;
const int inf = (int)1.05e9;

i64 waf(i64 s)
{
	i64 lo = 1;
	i64 hi = 1.05e9;

	while(hi - lo > 1) {
		i64 mid = (lo + hi) / 2;
		i64 rev = (s - 1) / mid;
		if(mid < rev)
			lo = mid;
		else
			hi = mid;
	}

	return lo;
}

int main()
{
	int q;

	scanf("%d", &q);

	for(int q_i = 0; q_i < q; ++q_i) {

		i64 a, b;
		scanf("%lld%lld", &a, &b);

		if(a > b)
			swap(a, b);

		if(a * b <= 2) {
			printf("0\n");
			continue;
		}

		i64 r = waf(a * b);

		i64 ans = 2 * r;
		if((r + 1) * (r + 1) < a * b && a != r + 1)
			ans += 1;

		if(a <= r) {
			ans -= 1;
		}

		printf("%lld\n", ans);
	}

	return 0;
}

/* waffle */
