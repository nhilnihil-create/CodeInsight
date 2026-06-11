
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
static const LLONG MOD_NUM = 1000000007;//998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
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
	int N, M;
	get(N, M);

	int ans = 1900 * M;
	ans += (100 * (N - M));

	while (M) {
		ans *= 2;
		M--;
	}

	printf("%d\n", ans);
}
