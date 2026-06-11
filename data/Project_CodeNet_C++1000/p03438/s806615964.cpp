
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
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

static void APetrC001B();

#if 1
int main()
{
	APetrC001B();
	fflush(stdout);
	return 0;
}
#endif

static void APetrC001B()
{
	int N;
	getint(N);

	std::vector<LLONG> an(N), bn(N);

	for (int i = 0; i < N; i++) {
		getint(an[i]);
	}
	for (int i = 0; i < N; i++) {
		getint(bn[i]);
	}

	LLONG plusCount = 0, minusCount = 0;
	for (int i = 0; i < N; i++) {
		LLONG diff = bn[i] - an[i];
		if (diff >= 0) {
			plusCount += diff / 2;
		}
		else {
			minusCount -= diff;
		}
	}
	printf("%s\n", (plusCount >= minusCount) ? "Yes" : "No");
}
