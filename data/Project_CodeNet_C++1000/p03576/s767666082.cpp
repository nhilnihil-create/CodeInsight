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
	vector<pair<int, int>> c;
	for (auto i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		c.push_back({ x, y });
	}

	auto ans = LLONG_MAX;
	sort(c.begin(), c.end());
	for (auto i = 0; i <= N - K; ++i)
	{
		for (auto j = i + K - 1; j < N; ++j)
		{
			vector<int> y;
			for (auto k = i; k <= j; ++k)
			{
				y.push_back(c[k].second);
			}

			sort(y.begin(), y.end());
			for (auto k = 0; k <= (int)y.size() - K; ++k)
			{
				ll diffX = c[j].first - c[i].first;
				ll diffY = y[k + K - 1] - y[k];
				ans = min(ans, diffX * diffY);
			}

		}
	}

	cout << ans << endl;

	return 0;
}