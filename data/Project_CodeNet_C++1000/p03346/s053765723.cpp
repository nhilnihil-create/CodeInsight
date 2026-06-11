
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

static void AGC024B();

#if 1
int main()
{
	AGC024B();
	fflush(stdout);
	return 0;
}
#endif

static void AGC024B()
{
	int N;
	getint(N);

	std::vector<int> pi(N + 1, 0);
	for (int i = 0; i < N; i++) {
		int p;
		getint(p);
		pi[p] = pi[p - 1] + 1;
	}

	int maxSlope = 0;
	for (int i = 1; i <= N; i++) {
		maxSlope = std::max(maxSlope, pi[i]);
	}

	printf("%d\n", N - maxSlope);
}
