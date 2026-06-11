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

int main()
{
	int N;
	ll K;
	cin >> N >> K;

	auto maxBit = 42;
	vector<vector<ll>> sumBit(2, vector<ll>(maxBit));
	for (auto i = 0; i < N; ++i)
	{
		ll A;
		cin >> A;
		for (auto j = 0; j < maxBit; ++j)
		{
			auto bit = 1ll << j;
			if ((A & bit) != 0)
			{
				sumBit[1][j] += bit;
			}
			else
			{
				sumBit[0][j] += bit;
			}
		}
	}

	vector<ll> sum;
	sum.push_back(0);
	for (auto i = 0; i < maxBit; ++i)
	{
		sum.push_back(sum[i] + max(sumBit[0][i], sumBit[1][i]));
	}

	auto current = 0ll;
	for (auto i = 0; i < maxBit; ++i)
	{
		if ((K & (1ll << i)) != 0)
		{
			current += sumBit[0][i];
		}
		else
		{
			current += sumBit[1][i];
		}
	}

	auto ans = current;
	for (auto i = 0; i < maxBit; ++i)
	{
		if ((K & (1ll << i)) != 0)
		{
			current -= sumBit[0][i];
			auto temp = current + sum[i] + sumBit[1][i];
			ans = max(ans, temp);
		}
		else
		{
			current -= sumBit[1][i];
		}
	}
	cout << ans << endl;


	return 0;
}