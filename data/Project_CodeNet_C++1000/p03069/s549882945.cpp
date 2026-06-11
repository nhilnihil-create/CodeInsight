
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

static void Tenk1PBC2019C();

#if 1
int main()
{
	Tenk1PBC2019C();
	fflush(stdout);
	return 0;
}
#endif

static void Tenk1PBC2019C()
{
	int N;
	getint(N);

	std::string orgs;
	std::cin >> orgs;

	//	まず白の数を数える
	int whiteCount = 0;
	for (int i = 0; i < N; i++) {
		if (orgs[i] != '#') {
			whiteCount++;
		}
	}

	int ans = whiteCount;
	int white = 0, black = 0;
	for (int i = 0; i < N; i++) {
		if (orgs[i] == '#') {
			black++;
		}
		else {
			white++;
		}
		
		ans = std::min(ans, black + whiteCount - white);
	}

	printf("%d\n", ans);
}
