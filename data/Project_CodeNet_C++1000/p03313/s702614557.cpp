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


vector<int> my_solution(vector<int> arr)
{
	vector<int> resp;
	vector<pair<int, int>> wo[21];
	for (int bit = 0; bit < 21; bit++) {
		vector<int> ids;
		for (int j = 0; j < arr.size(); j++)
		{
			if ((1 << bit) & j)
				continue;
			ids.push_back(j);
		}

		vector<int> tmp = { arr[ids[0]] };
		vector<pair<int, int>> best;
		//best.push_back({ 0,0 });
		int best_sum = 0;
		for (int j = 1; j < ids.size(); j++)
		{
			tmp.push_back(arr[ids[j]]);
			sort(tmp.begin(), tmp.end(), std::greater<int>());
			if (tmp.size() > 2)
				tmp.pop_back();
			best_sum = max(best_sum, tmp[0] + tmp[1]);
			best.push_back({ ids[j], best_sum });
		}
		wo[bit] = best;
	}

	for (int k = 0; k + 1 < arr.size(); k++)
	{
		int kk = k + 2;
		int best_ans = 0;
		for (int j = 0; j < 21; j++)
		{
			if ((kk & (1 << j)) == 0)
				continue;

			pair<int, int> xx = { kk, -1 };
			auto x = lower_bound(wo[j].begin(), wo[j].end(), xx);

			if (x == wo[j].begin())
				continue;
			{

				x--;
			}

			best_ans = max(best_ans, x->second);
		}
		resp.push_back(best_ans);
		//cout << best_ans << "\n";
	}
	return resp;
}

typedef pair < long  long, long  long > pll;
const  long  long INF = 1LL << 60;

void chmax(pll& a, pll b) {
	if (a.first < b.first) {
		a.second = max(a.first, b.second);
		a.first = b.first;
	}
	else a.second = max(a.second, b.first);
}

vector<int> correct_solution(vector<int> A, int N)
{
	vector<int> resp;
	 vector <pll> dp(1 << N);
	for (int bit = 0; bit < (1 << N); ++bit) {
		dp[bit] = { A[bit], -INF };
	}
	for (int i = 0; i < N; ++i)
		for (int bit = 0; bit < (1 << N); ++bit)
			if (bit & (1 << i))
				chmax(dp[bit], dp[bit ^ (1 << i)]);
	long  long res = -INF;
	for (int bit = 0; bit < (1 << N); ++bit) {
		long  long tmp = dp[bit].first + dp[bit].second;
		res = max(res, tmp);
		if (bit) resp.push_back(res);
	}
	return resp;
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
	vector<int> arr(1 << n);
	for (int i = 0; i < arr.size(); i++)
		cin >> arr[i];

	vector<vector<int>> dp(1 << n);
	for (int i = 0; i < (1<<n); i++)
		dp[i].push_back(arr[i]);
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < (1 << n); i++)
		{
			if (i & (1 << j))
			{
				int ii = i ^ (1 << j);
				std::copy(dp[ii].begin(), dp[ii].end(), std::back_inserter(dp[i]));
			}
			sort(dp[i].begin(), dp[i].end(), std::greater<>());
			while (dp[i].size() > 2)
				dp[i].pop_back();
		}
	}

	int res = 0;
	for (int i = 1; i < (1 << n); i++)
	{
		res = max(res, dp[i][0] + dp[i][1]);
		cout << res << "\n";
	}

	return 0;
}