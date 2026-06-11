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

	auto isBipartite = true;
	stack<int> s;
	vector<int> part(N);
	s.push(0);
	part[0] = 1;
	int partNum[] = { 0, 0, 1 };
	while (!s.empty())
	{
		auto u = s.top();
		s.pop();
		for (auto v : G[u])
		{
			if (part[v] != 0)
			{
				if (part[v] != -part[u])
				{
					isBipartite = false;
					break;
				}
				continue;
			}

			part[v] = -part[u];
			++partNum[part[v] + 1];
			s.push(v);
		}

		if (!isBipartite)
		{
			break;
		}
	}

	if (!isBipartite)
	{
		cout << (ll)N * (N - 1) / 2 - M << endl;
	}
	else
	{
		cout << (ll)partNum[0] * partNum[2] - M << endl;
	}

	return 0;
}