#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <math.h>
#include <map>
#include <iomanip>
#include <functional>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

template<class T> ostream& operator<<(ostream& os, const vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) os << *i << (i == end(v) - 1 ? "" : " "); return os;
}
template<class T> istream& operator>>(istream& is, vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) is >> *i; return is;
}

long long get_kth_a(long long a, long long k)
{
	if (k < a)
		return k;
	else
		return k + 1;
}

long long check(long long a, long long b, long long n)
{
	long long worst = 0;

	for (long long tmp = max(1LL, n / 2 - 100); tmp <= min(n, n / 2 + 100); tmp++) 
	{
		long long realb = tmp;
		if (tmp >= b)
			realb++;
		worst = max(worst, realb * get_kth_a(a, n -tmp+1));
	}
	return worst;
}


int main() {

#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;

	auto xxx = check(10, 5, 13);

	for (int i = 0; i < q; i++)
	{
		long long a, b;
		cin >> a >> b;

		long long best = 0;
		long long left = 0, right = 3000000001LL; // a * b + 1LL;
		while (left <= right)
		{
			long long m = left + (right - left) / 2LL;
			if (check(a, b, m) < (a*b))
			{
				left = m + 1;
				best = max(best, m);
			}
			else
			{
				right = m - 1;
			}
		}

		cout << best << "\n";
	}


	return 0;
}
