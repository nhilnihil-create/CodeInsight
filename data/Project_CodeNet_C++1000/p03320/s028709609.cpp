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
#include <random>
#include <set>

using namespace std;

template<class T> ostream& operator<<(ostream& os, const vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) os << *i << (i == end(v) - 1 ? "" : " "); return os;
}
template<class T> istream& operator>>(istream& is, vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) is >> *i; return is;
}

#define MOD 1000000007
#define inf 2000000000

long long nearest_wsum(long long x, int sum)
{
	long long orig_x = x;
	vector<int> vec;
	int curr_sum = 0;
	while (x > 0)
	{
		vec.push_back(x % 10);
		curr_sum += x % 10;
		x /= 10;
	}

	while (vec.size() < 17)
		vec.push_back(0);

	if (curr_sum == sum)
		return orig_x;
	if (curr_sum < sum)
	{
		sum -= curr_sum;
		for (int j = 0; sum > 0 && j < vec.size(); j++)
		{
			int ava = 9 - vec[j];
			int inc = min(sum, ava);
			vec[j] += inc;
			sum -= inc;
		}
	}
	else
	{
		int acc = 0;
		for (int j = 0; j < vec.size(); j++)
		{
			if (vec[j] != 9 && acc > (curr_sum - sum))
			{
				curr_sum -= acc;
				vec[j]++; curr_sum++;

				for (int k = 0; curr_sum < sum && k < vec.size(); k++)
				{
					int ava = min(9, sum - curr_sum);
					vec[k] = ava;
					curr_sum += ava;
				}

				break;
			}
			acc += vec[j];
			vec[j] = 0;
		}
	}

	long long resp = 0;
	for (int j = vec.size() - 1; j >= 0; j--)
	{
		resp *= 10LL;
		resp += vec[j];
	}

	return resp;
}

int main() {

#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int k;
	cin >> k;


	cout << 1 << "\n";
	long long prev_num = 1;

	for (int j = 2; j <= k; j++)
	{
		pair<long long, long long> best_pair = { nearest_wsum(prev_num + 1LL, 1), 1LL };
		for (long long denom = 2; denom <= 135; denom++)
		{
			pair<long long, long long> candidate = { nearest_wsum(prev_num + 1LL, denom), denom };
			if (candidate.first * best_pair.second < best_pair.first * candidate.second)
			{
				best_pair = candidate;
			}
		}

		cout << best_pair.first << "\n";
		prev_num = best_pair.first;
	}

	return 0;
}
