
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#ifndef U_L_LONG
typedef unsigned long long ULLONG;
#endif
#ifndef L_LONG
typedef long long LLONG;
#endif

static const LLONG MOD_NUM = 1000000007;

template <class _T> static _T tp_abs(const _T& a) {
	//	usage:  tp_abs<type name>(a);
	return ((a < 0) ? (a * -1) : a);
}
template <class _T> static _T tp_min(_T a, _T b) {
	return a < b ? a : b;
}
template <class _T> static _T tp_max(_T a, _T b) {
	return a > b ? a : b;
}
template<class _T> static void get1int(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void get2int(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class _T> static void get3int(_T& a, _T& b, _T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld %lld";
	}

	if (scanf(fmt, &a, &b, &c) < 0) {
		printf("g3int Error\n");
	}
}
template <class _T> static void tp_swap(_T& right, _T& left) {
	//	usage:  tp_swap<type name>(a, b);
	_T tmp = right;
	right = left;
	left = tmp;
}
static void getstring(char* buff) {
	if (scanf(" %s", buff) < 0) {
		printf("getstr error!\n");
	}
}
template <class _T> static _T tp_pow(int base, int exp)
{
	_T ans = 1;

	for (int i = 0; i < exp; i++) {
		ans *= base;
	}
	return ans;
}


static void ABC104D_WeLoveABC();

#if 1
int main()
{
	ABC104D_WeLoveABC();
	fflush(stdout);
	return 0;
}
#endif



static void ABC104D_WeLoveABC()
{
	int MaxLen = 100000;
	LLONG mod = 1000000007LL;
	
	auto str = new char[MaxLen + 1];
	memset(str, 0, sizeof(str[0]) * (MaxLen + 1));
	
	getstring(str);
	int len = strlen(str);
	
	auto dp = new LLONG[len + 1][4];
	memset(dp, 0, sizeof(LLONG) * (len + 1) * 4);

	dp[0][0] = 1;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 4; j++) {
			if (str[i] == '?') {
				dp[i + 1][j] = dp[i][j] * 3;
			}
			else {
				dp[i + 1][j] = dp[i][j];
			}
			dp[i + 1][j] %= MOD_NUM;
		}

		if ((str[i] == 'A') || (str[i] == '?')) {
			dp[i + 1][1] += dp[i][0];
			dp[i + 1][1] %= MOD_NUM;
		}
		if ((str[i] == 'B') || (str[i] == '?')) {
			dp[i + 1][2] += dp[i][1];
			dp[i + 1][2] %= MOD_NUM;
		}
		if ((str[i] == 'C') || (str[i] == '?')) {
			dp[i + 1][3] += dp[i][2];
			dp[i + 1][3] %= MOD_NUM;
		}
	}

	printf("%lld\n", dp[len][3]);

	delete[] dp;
	delete[] str;
}
