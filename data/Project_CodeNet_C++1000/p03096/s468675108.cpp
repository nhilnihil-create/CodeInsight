
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
	std::cin >> a;
}
template<class _T> static void getint(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void AGC031B();

int main()
{
	AGC031B();
	fflush(stdout);
	return 0;
}

static void AGC031B()
{
	int N;
	getint(N);

	std::vector<int> ci(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		getint(ci[i]);
	}

	std::vector<int> lastPos(2 * 100000 + 1, 0);
	std::vector<LLONG> dp(N + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1];
		int lpos = lastPos[ci[i]];
		if ((lpos > 0) && (lpos < (i - 1))) {
			dp[i] = (dp[i] + dp[lpos]) % MOD_NUM;
		}
		lastPos[ci[i]] = i;
	}
	printf("%lld\n", dp[N]);
}
