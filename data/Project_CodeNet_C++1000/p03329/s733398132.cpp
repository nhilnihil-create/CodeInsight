#include <iostream>
#include <iomanip>
#include <cassert>

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <queue>
#include <unordered_map>
#include <list>
#include <set>
#include <numeric>
using namespace std;

using ll = long long;

#define rep_init(i, init, n) for(int i = (init); i < (n); ++i)
#define rep(i, n) rep_init(i, 0, n)

int main()
{
	int N;
	cin >> N;

	vector<int> withdraw;
	for (int i = 6; i <= N; i *= 6)
	{
		withdraw.push_back(i);
	}
	for (int i = 9; i <= N; i *= 9)
	{
		withdraw.push_back(i);
	}

	sort(withdraw.begin(), withdraw.end());

	vector<int> dp(N+1, 0);
	rep_init(i, 1, N+1)
	{
		dp[i] = dp[i-1] + 1;
		for (auto e : withdraw)
		{
			if (e > i) break;
			dp[i] = min(dp[i], dp[i-e] + 1);
		}
	}

	cout << dp[N] << endl;
}