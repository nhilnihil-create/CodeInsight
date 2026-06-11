#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007; //998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
}

static void exec();

int main()
{
	exec();
	fflush(stdout);
	return 0;
}

static void exec()
{
	int K;
	get(K);

	std::vector<int> ai(K);
	for (int i = 0; i < K; i++) {
		get(ai[i]);
	}

	if (ai[K - 1] != 2) {
		printf("-1\n");
		return;
	}

	LLONG min = 2, max = 2;
	for(int i = K - 1; i >= 0; i--) {
		LLONG tmp = ai[i];
		bool ok = false;

		LLONG div = min / ai[i];
		if (min % ai[i]) {
			div++;
		}

		if (div * ai[i] > max) {
			printf("-1\n");
			return;
		}

		min = (min / ai[i] + ((min % ai[i]) ? 1 : 0)) * ai[i];
		max = (max / ai[i]) * ai[i] + ai[i] - 1;
	}
	printf("%lld %lld\n", min, max);
}
