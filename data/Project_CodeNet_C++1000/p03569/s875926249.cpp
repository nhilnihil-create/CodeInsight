
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

static void CodeFes2017qCC();

#if 1
int main()
{
	CodeFes2017qCC();
	fflush(stdout);
	return 0;
}
#endif

static void CodeFes2017qCC()
{
	std::string orgs;
	std::cin >> orgs;

	int top = 0, end = orgs.length() - 1;
	int xCount = 0;
	bool unmatch = false;
	while (top < end) {
		if (orgs[top] == orgs[end]) {
			top++;
			end--;
		}
		else if (orgs[top] == 'x') {
			xCount++;
			top++;
		}
		else if (orgs[end] == 'x') {
			xCount++;
			end--;
		}
		else {
			unmatch = true;
			break;
		}
	}
	if (unmatch) xCount = -1;
	printf("%d\n", xCount);
}
