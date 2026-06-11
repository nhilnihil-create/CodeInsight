
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007; //998244353;

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
	LLONG N;
	get(N);

	std::vector<int> num;
	int digit = 0;
	LLONG tmp = N;
	while (tmp) {
		digit++;
		num.push_back(tmp % 10LL);
		tmp /= 10LL;
	}

	bool all9 = true;
	for (int i = 0; i < digit - 1; i++) {
		if (num[i] != 9) {
			all9 = false;
		}
	}

	int ans = 0;
	if (all9) {
		for (int i = 0; i < digit; i++) {
			ans += num[i];
		}
	}
	else {
		for (int i = 0; i < digit - 1; i++) {
			ans += 9;
		}
		ans += num[digit - 1] - 1;
	}
	printf("%d\n", ans);
}
