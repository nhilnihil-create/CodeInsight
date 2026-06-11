#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

void primeFactorization(ll n, map<ll, int>& result)
{
	for (auto i = 2ll; i * i <= n; ++i)
	{
		while (n % i == 0)
		{
			++result[i];
			n /= i;
		}
	}

	if (n != 1)
	{
		++result[n];
	}
}

int main()
{
	int N;
	cin >> N;
	map<ll, int> m;
	for (auto i = 2; i <= N; ++i)
	{
		primeFactorization(i, m);
	}

	vector<int> num;
	for (auto& p : m)
	{
		num.push_back(p.second);
	}
	vector<vector<ll>> dp((int)num.size() + 1, vector<ll>(76));
	dp[0][1] = 1;
	for (auto i = 0; i < (int)num.size(); ++i)
	{
		for (auto k = 0; k <= 75; ++k)
		{
			for (auto j = 0; j <= num[i]; ++j)
			{
				if (k * (j + 1) > 75)
				{
					break;
				}
				dp[i + 1][k * (j + 1)] += dp[i][k];
			}
		}
	}

	cout << dp[(int)num.size()][75] << endl;

	return 0;
}