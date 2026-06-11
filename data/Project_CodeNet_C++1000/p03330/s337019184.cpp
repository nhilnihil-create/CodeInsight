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
	vector<vector<int>> D(C, vector<int>(C));
	for (auto& tempD : D)
	{
		for (auto& d : tempD)
		{
			cin >> d;
		}
	}

	vector<vector<int>> num(3, vector<int>(C));
	for (auto i = 1; i <= N; ++i)
	{
		for (auto j = 1; j <= N; ++j)
		{
			int c;
			cin >> c;
			--c;
			auto index = (i + j) % 3;
			++num[index][c];
		}
	}

	auto ans = INT_MAX;
	for (auto i = 0; i < C; ++i)
	{
		for (auto j = 0; j < C; ++j)
		{
			if (i == j)
			{
				continue;
			}

			for (auto k = 0; k < C; ++k)
			{
				if (i == k || j == k)
				{
					continue;
				}

				auto sum = 0;
				for (auto l = 0; l < C; ++l)
				{
					sum += D[l][i] * num[0][l];
					sum += D[l][j] * num[1][l];
					sum += D[l][k] * num[2][l];
				}
				ans = min(ans, sum);
			}
		}
	}
	cout << ans << endl;

	return 0;
}