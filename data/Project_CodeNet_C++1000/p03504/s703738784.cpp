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
	int N, C;
	cin >> N >> C;
	vector<vector<pair<int, int>>> list(C);
	for (auto i = 0; i < N; ++i)
	{
		int s, t, c;
		cin >> s >> t >> c;
		--c;
		list[c].push_back({ s, t });
	}

	vector<int> sum(2 * (int)1e5 + 1);
	for (auto i = 0; i < C; ++i)
	{
		sort(list[i].begin(), list[i].end());
		for (auto j = 0; j < (int)list[i].size(); ++j)
		{
			auto right = j;
			auto s = list[i][j].first;
			auto t = list[i][j].second;
			for (auto k = j + 1; k < (int)list[i].size(); ++k)
			{
				auto tempS = list[i][k].first;
				if (tempS == t)
				{
					t = list[i][k].second;
					j = k;
				}
				else
				{
					break;
				}
			}

			++sum[2 * s - 1];
			--sum[2 * t];
		}
	}

	auto ans = 0;
	for (auto i = 0; i < (int)sum.size() - 1; ++i)
	{
		sum[i + 1] += sum[i];
		ans = max(ans, sum[i + 1]);
	}
	cout << ans << endl;

	return 0;
}