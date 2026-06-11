#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
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
	int N, M;
	cin >> N >> M;
	vector<vector<int>> G(N);
	for (auto i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		--A;
		--B;
		G[A].push_back(B);
		G[B].push_back(A);
	}

	auto even = 0;
	vector<int> list(N, -1);
	queue<pair<int, bool>> q;
	q.push({ 0, false });
	vector<bool> used(N);
	bool all = false;
	used[0] = true;
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		if (p.second)
		{
			++even;
			list[p.first] = 1;
		}
		else
		{
			list[p.first] = 0;
		}

		for (auto v : G[p.first])
		{
			if (list[v] >= 0 && list[p.first] == list[v])
			{
				all = true;
				break;
			}

			if (used[v])
			{
				continue;
			}

			used[v] = true;
			q.push({ v, !p.second });
		}

		if (all)
		{
			break;
		}
	}

	auto result = 0ll;
	if (all)
	{
		result = (ll)N * (N - 1) / 2 - M;
	}
	else
	{
		for (auto i = 0; i < N; ++i)
		{
			auto num = even;
			if (list[i])
			{
				num = N - num;
			}
			num -= G[i].size();
			result += num;
		}

		result /= 2;
	}

	cout << result << endl;

	return 0;
}