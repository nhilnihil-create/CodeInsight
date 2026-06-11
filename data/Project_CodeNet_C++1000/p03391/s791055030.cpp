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


int main() {

#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	long long total = 0;
	vector<int> a(n), b(n);
	int max_b = 1e9+1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		total += a[i];
		if (b[i] < a[i])
			max_b = min(max_b, b[i]);
	}

	if (a == b)
	{
		cout << 0;
	}
	else
	{
		cout << total - max_b;
	}



	return 0;
}
