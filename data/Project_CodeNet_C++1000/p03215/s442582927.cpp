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
	int N, K;
	cin >> N >> K;
	vector<ll> a(N);
	for (auto& temp : a)
	{
		cin >> temp;
	}

	vector<ll> sum(N + 1);
	for (auto i = 0; i < N; ++i)
	{
		sum[i + 1] = sum[i] + a[i];
	}

	vector<ll> list;
	for (auto i = 0; i < N; ++i)
	{
		for (auto j = i; j < N; ++j)
		{
			list.push_back(sum[j + 1] - sum[i]);
		}
	}

	auto ans = 0ll;
	for (auto i = 45; i >= 0; --i)
	{
		auto bit = (1ll << i);
		auto sum = 0ll;
		for (auto j = 0; j < (int)list.size(); ++j)
		{
			if ((list[j] & ans) != ans)
			{
				continue;
			}
			if ((list[j] & bit) == 0)
			{
				continue;
			}
			++sum;
		}
		if (sum >= K)
		{
			ans |= bit;
		}
	}

	cout << ans << endl;

	return 0;
}