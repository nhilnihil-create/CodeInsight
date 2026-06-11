
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
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

template<class _T> static void getval(_T& a) {
	std::cin >> a;
}
template<class _T> static void getval(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getval(_T& a, _T& b, _T& c) {
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
	int N;
	getval(N);

	LLONG Z, W;
	getval(Z, W);

	LLONG last2Val = 0, lastVal = 0;
	LLONG ai = 0;
	for (int i = 0; i < N; i++) {
		getval(ai);
		if (i == N - 2) {
			last2Val = ai;
		}
	}
	lastVal = ai;


	LLONG ans = 0;
	LLONG x, y;
	
	x = lastVal;
	y = W;
	ans = tp_abs(x - y);
	if (N == 1) {
		printf("%lld\n", ans);
		return;
	}

	x = lastVal;
	y = last2Val;
	ans = std::max(ans, tp_abs(x - y));

	printf("%lld\n", ans);
}
