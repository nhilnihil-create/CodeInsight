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
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<vector<int>> sum(N, vector<int>(N));
	for (auto i = 0; i < M; ++i)
	{
		int L, R;
		cin >> L >> R;
		--L;
		--R;
		++sum[L][R];
	}

	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 1; j < N; ++j)
		{
			sum[i][j] += sum[i][j - 1];
		}
	}

	vector<vector<int>> sum2(N, vector<int>(N));
	for (auto i = 0; i < N; ++i)
	{
		for (auto j = i; j < N; ++j)
		{
			for (auto left = i; left < N; ++left)
			{
				sum2[i][j] += sum[left][j];
			}
		}
	}

	vector<int> ans;
	for (auto i = 0; i < Q; ++i)
	{
		int p, q;
		cin >> p >> q;
		--p;
		--q;
		ans.push_back(sum2[p][q]);
	}

	for (auto i = 0; i < Q; ++i)
	{
		cout << ans[i] << endl;
	}

	return 0;
}