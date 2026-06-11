
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

static void AGC031A();

#if 1
int main()
{
	AGC031A();
	fflush(stdout);
	return 0;
}
#endif

static void AGC031A()
{
	int N;
	getint(N);

	std::string orgs;
	std::cin >> orgs;

	std::map<char, LLONG> chars;
	std::vector<LLONG> dp(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1];
		
		LLONG use = 1;
		int kind = chars.size();
		for(auto it = chars.begin(); it != chars.end(); it++) {
			if (it->first != orgs[i - 1]) {
				use = (use * (it->second + 1)) % MOD_NUM;
			}
		}

		dp[i] = (dp[i] + use) % MOD_NUM;
		chars[orgs[i - 1]]++;
	}
	printf("%lld\n", dp[N]);
}
