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
	vector<vector<int>> m(N, vector<int>(N));
	for (auto i = 0; i < M; ++i)
	{
		int L, R;
		cin >> L >> R;
		--L;
		--R;
		++m[0][R];
		if (L + 1 < N)
		{
			--m[L + 1][R];
		}
	}

	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 1; j < N; ++j)
		{
			m[j][i] += m[j - 1][i];
		}
	}
	for (auto i = 1; i < N; ++i)
	{
		for (auto j = 0; j < N; ++j)
		{
			m[j][i] += m[j][i - 1];
		}
	}

	vector<int> ans;
	for (auto i = 0; i < Q; ++i)
	{
		int p, q;
		cin >> p >> q;
		--p;
		--q;
		ans.push_back(m[p][q]);
	}

	for (auto i = 0; i < Q; ++i)
	{
		cout << ans[i] << endl;
	}

	return 0;
}