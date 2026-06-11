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


int main()
{
#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> a, b;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}

	int ans = 0;
	for (int bit = 0; bit < 30; bit++)
	{
		vector<int> aa, bb;
		int mask = (2 << bit) - 1;
		for (int x : a)
		{
			aa.push_back(x & mask);
		}

		for (int x : b)
		{
			bb.push_back(x & mask);
		}

//		sort(aa.begin(), aa.end());
		sort(bb.begin(), bb.end());
		int bit_val = 0;
		for (int x : aa)
		{
			int maxbit = (1 << bit) & x;
			if (maxbit == 0)
			{
				int from = (1 << bit) - x;
				int to = mask - x;

				auto from_it = lower_bound(bb.begin(), bb.end(), from);
				auto to_it = upper_bound(bb.begin(), bb.end(), to);
				bit_val ^= (to_it - from_it) % 2;
			}
			else
			{
				int from = (1 << (bit + 1)) - x;
				int to = from + (1 << bit) - 1;
				auto from_it = lower_bound(bb.begin(), bb.end(), from);
				auto to_it = upper_bound(bb.begin(), bb.end(), to);
				int cnt1 = bb.size() - (to_it - from_it);
				bit_val ^= cnt1 % 2;
			}
		}
		ans |= bit_val * (1 << bit);
	}

	cout << ans;

	return 0;
}