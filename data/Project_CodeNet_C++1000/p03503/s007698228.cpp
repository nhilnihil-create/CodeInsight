
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
template<class _T> static void getint(_T& a) {
	if (sizeof(_T) > sizeof(int)) {
		scanf("%lld", &a);
	}
	else {
		scanf("%d", &a);
	}
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
	get(N);

	std::vector<std::vector<int>> open(N, std::vector<int>(10, 0)), prof(N, std::vector<int>(11, 0));

	for (int i = 0; i < N; i++) {
		for (int t = 0; t < 10; t++) {
			get(open[i][t]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int t = 0; t <= 10; t++) {
			get(prof[i][t]);
		}
	}

	int ans = -MOD_NUM;
	for (int bit = 1; bit < (1 << 10); bit++) {
		std::vector<int> match(N, 0);
		for (int day = 0; day < 10; day++) {
			if (bit & (1 << day)) {
				for (int i = 0; i < N; i++) {
					if (open[i][day]) {
						match[i]++;
					}
				}
			}
		}
		int pr = 0;
		for (int i = 0; i < N; i++) {
			pr += prof[i][match[i]];
		}
		ans = std::max(ans, pr);
	}
	printf("%d\n", ans);
}
