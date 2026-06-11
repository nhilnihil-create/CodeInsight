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

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> G(N + 1);
	for (auto i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vector<int> c(N);
	auto sum = 0ll;
	for (auto i = 0; i < N; ++i)
	{
		cin >> c[i];
		sum += c[i];
	}
	sort(c.begin(), c.end(), greater<int>());
	sum -= c[0];

	bool used[10001];
	memset(used, 0, sizeof(used));
	queue<int> q;
	q.push(1);
	vector<int> result(N);
	auto index = 0;
	while (!q.empty())
	{
		auto x = q.front();
		q.pop();
		if (used[x])
		{
			continue;
		}

		result[x - 1] = c[index];
		++index;
		used[x] = true;

		for (auto n : G[x])
		{
			if (used[n])
			{
				continue;
			}

			q.push(n);
		}
	}

	cout << sum << endl;
	for (auto i = 0; i < N; ++i)
	{
		cout << result[i];
		if (i < N - 1)
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}