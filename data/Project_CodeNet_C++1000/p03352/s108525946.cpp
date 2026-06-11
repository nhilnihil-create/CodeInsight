
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
template <class _T> static _T tp_pow(int base, int exp)
{
	_T ans = 1;

	for (int i = 0; i < exp; i++) {
		ans *= (_T)base;
	}
	return ans;
}

static void D();

int main()
{
	D();
	fflush(stdout);
	return 0;
}

static void D()
{
	int X;
	get(X);
	
	int base = 1, exp = 0, ans = 1;
	for (base = 1; base <= X; base++) {
		for (exp = 2; exp <= X; exp++) {
			int tmp = tp_pow<int>(base, exp);
			if (tmp > X) break;
			ans = std::max(ans, tmp);
		}
	}
	printf("%d\n", ans);
}
