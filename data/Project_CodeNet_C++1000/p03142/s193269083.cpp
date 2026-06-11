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
	vector<int> in(N);
	for (auto i = 0; i < N - 1 + M; ++i)
	{
		int A, B;
		cin >> A >> B;
		G[A - 1].push_back(B - 1);
		++in[B - 1];
	}

	stack<int> s;
	auto root = 0;
	for (auto i = 0; i < N; ++i)
	{
		if (in[i] == 0)
		{
			root = i;
			s.push(i);
			break;
		}
	}

	vector<int> index(N);
	auto next = 1;
	while (!s.empty())
	{
		auto u = s.top();
		s.pop();
		index[u] = next;
		++next;

		for (auto v : G[u])
		{
			--in[v];
			if (in[v] == 0)
			{
				s.push(v);
			}
		}
	}

	vector<int> maxIndex(N);
	vector<int> result(N);
	for (auto i = 0; i < N; ++i)
	{
		for (auto v : G[i])
		{
			if (maxIndex[v] < index[i])
			{
				maxIndex[v] = index[i];
				result[v] = i + 1;
			}
		}
	}

	for (auto i = 0; i < N; ++i)
	{
		cout << result[i] << endl;
	}

	return 0;
}