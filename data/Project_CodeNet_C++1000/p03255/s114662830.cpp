#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 200000;
int n, w, p[N];
ll calc(int g) {
	vector<ll> sz(g, 0);
	ll res = 0;
	for (int j = 0; j < n; ++j) {
		int i = j%g;
		++sz[i];
		res += ((sz[i] + 1)*(sz[i] + 1) - (sz[i] > 1)*sz[i] * sz[i])*p[j];
		if (j < g)
			res += p[j];
	}
	res += (ll)g*w;
	res += (ll)n*w;
	return res;
}
int main()
{
	scanf("%d%d", &n, &w);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i);
	reverse(p, p + n);
	int l = 1, r = n, m, l1, l2;
	ll r1, r2, res = 1e18;
	while (l <= r) {
		l1 = (2 * l + r) / 3;
		l2 = (l + 2 * r) / 3;
		r1 = calc(l1);
		r2 = calc(l2);
		res = min(res, min(r1, r2));
		if (r2 > r1)
			r = l2 - 1;
		else
			l = l1 + 1;
	}
	printf("%lld\n", res);
	return 0;
}