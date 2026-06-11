
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
static const LLONG MOD_NUM = 998244353; //1000000007;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void A();

int main()
{
	A();
	fflush(stdout);
	return 0;
}

static void A()
{
	int N;
	get(N);

	const char* ans = "Yes\n";
	std::vector<LLONG> ai(N), bi(N);
	for (int i = 0; i < N; i++) {
		get(ai[i]);
	}
	for (int i = 0; i < N; i++) {
		get(bi[i]);
	}
	LLONG sum = 0, plus = 0, minus = 0;
	for (int i = 0; i < N; i++) {
		LLONG diff = bi[i] - ai[i];
		sum += diff;
		if (diff < 0) {
			minus -= diff;
		}
		else {
			plus += (diff + 1) / 2;
		}
	}
	if (std::max(plus, minus) > sum) {
		ans = "No\n";
	}

	printf(ans);
}
