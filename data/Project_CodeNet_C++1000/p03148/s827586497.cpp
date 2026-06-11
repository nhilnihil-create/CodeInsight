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
	vector<pair<ll, int>> list;
	vector<pair<ll, int>> maxList(N);
	for (auto i = 0; i < N; ++i)
	{
		int t;
		ll d;
		cin >> t >> d;
		--t;
		list.push_back({ d, i });
		if (maxList[t].first < d)
		{
			maxList[t].first = d;
			maxList[t].second = i;
		}
	}

	sort(maxList.begin(), maxList.end());
	sort(list.begin(), list.end(), greater<pair<ll, int>>());
	auto ans = 0ll;
	auto sum = 0ll;
	auto kind = 0ll;
	auto num = 0ll;
	vector<bool> used(N);
	auto index2 = 0;
	for (auto i = N - 1; i >= 0 && num < K; --i)
	{
		if (maxList[i].first > 0)
		{
			used[maxList[i].second] = true;
			sum += maxList[i].first;
			++kind;
			++num;
			index2 = i;
		}
	}

	auto index1 = 0;
	for (; index1 < N; ++index1)
	{
		if (used[list[index1].second] != false)
		{
			continue;
		}

		if (num >= K)
		{
			break;
		}

		sum += list[index1].first;
		used[list[index1].second] = true;
		++num;
	}

	ans = sum + kind * kind;

	while (index1 < N && list[index1].first > maxList[index2].first)
	{
		--kind;
		sum -= maxList[index2].first;
		sum += list[index1].first;

		ans = max(ans, sum + kind * kind);
		used[list[index1].second] = true;
		used[maxList[index2].second] = false;
		++index2;
		while (index1 < N && used[list[index1].second] != false)
		{
			++index1;
		}
	}

	cout << ans << endl;

	return 0;
}