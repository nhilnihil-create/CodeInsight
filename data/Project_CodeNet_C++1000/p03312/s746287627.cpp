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

vector<long long> from_left, from_right;

int first_gte(vector<long long> &vec, long long val, int right)
{
	int left = 0;
	while (left < right)
	{
		int m = (left + right) / 2;
		if (vec[m] >= val)
		{
			right = m;
		}
		else
		{
			left = m + 1;
		}
	}
	return left;
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
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	from_left.push_back(0);
	for (int i = 0; i < n; i++)
	{
		from_left.push_back(from_left.back() + arr[i]);
	}

	from_right.push_back(0);
	for (int i = n - 1; i >= 0; i--)
	{
		from_right.push_back(from_right.back() + arr[i]);
	}

	long long total_sum = from_left.back();
	long long best = total_sum;
	long long left_sum = arr[0] + arr[1];
	for (int i = 2; i + 1 < n; i++)
	{
		int left_idx = first_gte(from_left, (left_sum + 1LL) / 2LL, i);
		vector<pair<long long, long long>> vv_left;
		if (left_idx > 0)
			vv_left.push_back({ from_left[left_idx-1], left_sum - from_left[left_idx-1] });
		vv_left.push_back({ from_left[left_idx], left_sum - from_left[left_idx] });
		if (left_idx + 1 < i)
		{
			vv_left.push_back({ from_left[left_idx + 1], left_sum - from_left[left_idx + 1] });
		}

		long long right_sum = total_sum - left_sum;
		int right_idx = first_gte(from_right, (right_sum + 1LL) / 2LL, n - i + 1);
		vector<pair<long long, long long>> vv_right;
		if (right_idx > 0)	
			vv_right.push_back({ from_right[right_idx - 1], right_sum - from_right[right_idx - 1] });
		vv_right.push_back({ from_right[right_idx], right_sum - from_right[right_idx] });
		if (right_idx + 1 < (n - i + 1))
		{
			vv_right.push_back({ from_right[right_idx + 1], right_sum - from_right[right_idx + 1] });
		}

		for (auto x : vv_left)
		{
			
			for (auto y : vv_right)
			{
				long long minv = min(x.first, x.second), maxv = max(x.first, x.second);
				minv = min(minv, y.first); minv = min(minv, y.second);
				maxv = max(maxv, y.first); maxv = max(maxv, y.second);
				if (minv == 0)
					continue;
				best = min(best, maxv - minv);
			}
		}

		left_sum += arr[i];
	}

	cout << best;
	return 0;
}