
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

static void AGC023A();

#if 1
int main()
{
	AGC023A();
	fflush(stdout);
	return 0;
}
#endif

static void AGC023A()
{
	int N;
	getint(N);

	std::vector<LLONG> an(N, 0);
	for (int i = 0; i < N; i++) {
		getint(an[i]);
	}

	LLONG sum = 0;
	std::map<LLONG, LLONG> summap;
	summap[0] = 1;
	for (int i = 1; i <= N; i++) {
		sum = sum + an[i - 1];
		summap[sum]++;
	}

	LLONG ans = 0;
	for (auto it = summap.begin(); it != summap.end(); it++) {
		ans += (it->second * (it->second - 1LL)) / 2LL;
	}
	printf("%lld\n", ans);
}
