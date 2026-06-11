#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <list>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); ++i)

int main() {

	ll N, n = 0;
	scanf("%lld", &N);

	for (ll i = 1; i * (i + 1) / 2 < 112345; ++i) {
		if (N == i * (i + 1) / 2) {
			n = i;
			break;
		}
	}
	if (!n) {
		printf("No\n");
		return 0;
	}

	vector<vector<ll>> Ans(n + 1);
	ll unused = 1;

	rep(i, n + 1) {
		rep(j, i) {
			Ans[i].push_back(Ans[j][i - 1]);
		}
		for (; Ans[i].size() < n; ++unused) Ans[i].push_back(unused);
	}

	printf("Yes\n");
	printf("%lld\n", n + 1);
	rep(k, n + 1) {
		printf("%lld ", n);
		rep(Sk, n) printf("%lld ", Ans[k][Sk]);
		printf("\n");
	}
	return 0;
}