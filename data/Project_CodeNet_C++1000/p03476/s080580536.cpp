#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getint(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld %lld";
	}

	if (scanf(fmt, &a, &b, &c) < 0) {
		printf("g3int Error\n");
	}
}

static void ABC084D();

#if 1
int main()
{
	ABC084D();
	fflush(stdout);
	return 0;
}
#endif
template <class _T> void tp_getPrimes(_T targ, std::map<_T, _T>& primes)
{
	_T target = targ;
	_T i = 2;
	while ((i * i) <= target) {
		if ((target % i) == 0) {
			target /= i;
			primes[i]++;
		}
		else {
			i++;
		}
	}
	if (target > 1) {
		primes[target]++;
	}
}

static void ABC084D()
{
	int Q;
	getint(Q);
	std::vector<int> pnCounts(100001, 0);
	pnCounts[0] = 0;
	pnCounts[1] = 0;
	
	for (int i = 2; i < 100001; i++) {
		std::map<int, int> primes, primes2;
		pnCounts[i] = pnCounts[i - 1];

		if ((i % 2) == 0) continue;

		tp_getPrimes(i, primes);
		if ((primes.size() == 1) && (primes.begin()->second == 1)) {
			tp_getPrimes((i + 1) / 2, primes2);
			if ((primes2.size() == 1) && (primes2.begin()->second == 1)) {
				pnCounts[i]++;
			}
		}
	}

	for (int i = 0; i < Q; i++) {
		int li, ri;
		getint(li, ri);
		printf("%d\n", pnCounts[ri] - pnCounts[li - 1]);
	}
}
