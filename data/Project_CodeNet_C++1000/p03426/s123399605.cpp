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
	int H, W, D;
	cin >> H >> W >> D;
	vector<pair<int, int>> c(H * W);
	for (auto i = 0; i < H; ++i)
	{
		for (auto j = 0; j < W; ++j)
		{
			int A;
			cin >> A;
			--A;
			c[A] = { i, j };
		}
	}

	vector<ll> sum(H * W);
	for (auto i = D; i < H * W; ++i)
	{
		sum[i] = sum[i - D];
		auto& current = c[i];
		auto& prev = c[i - D];
		auto diffY = prev.first - current.first;
		auto diffX = prev.second - current.second;
		sum[i] += abs(diffX) + abs(diffY);
	}

	vector<ll> ans;
	int Q;
	cin >> Q;
	for (auto i = 0; i < Q; ++i)
	{
		int L, R;
		cin >> L >> R;
		--L;
		--R;
		ans.push_back(sum[R] - sum[L]);
	}

	for (auto i = 0; i < Q; ++i)
	{
		cout << ans[i] << endl;
	}

	return 0;
}