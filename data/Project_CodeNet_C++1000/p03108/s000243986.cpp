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

struct UFTree {
private:
	vector<int> mNode;
	vector<int> mRank;
	vector<int> mNodeNum;

public:
	UFTree(int n) : mNode(n), mRank(n), mNodeNum(n)
	{
		for (int i = 0; i < n; i++) {
			mNode[i] = i;
			mNodeNum[i] = 1;
		}
	}

	int find(int x)
	{
		if (mNode[x] == x) {
			return x;
		}
		else {
			mNode[x] = find(mNode[x]);
			return mNode[x];
		}
	}

	void unite(int x, int y)
	{
		int idxX = find(x);
		int idxY = find(y);

		if (idxX == idxY) {
			return;
		}

		if (mRank[idxX] > mRank[idxY]) {
			mNode[idxY] = idxX;
			mNodeNum[idxX] += mNodeNum[idxY];
		}
		else {
			mNode[idxX] = idxY;
			mNodeNum[idxY] += mNodeNum[idxX];
			if (mRank[idxX] == mRank[idxY]) {
				mRank[idxY]++;
			}
		}
	}

	bool isSameSet(int x, int y)
	{
		return find(x) == find(y);
	}

	int getNodeNum(int x)
	{
		auto node = find(x);
		return mNodeNum[node];
	}
};


int main()
{
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> e;
	for (auto i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		--A;
		--B;
		e.push_back({ A, B });
	}

	UFTree t(N);
	vector<ll> ans;
	ans.push_back((ll)N * (N - 1) / 2);
	for (auto i = M - 1; i > 0; --i)
	{
		auto p = e[i];
		auto num = *ans.rbegin();
		if (!t.isSameSet(p.first, p.second))
		{
			num -= (ll)t.getNodeNum(p.first) * t.getNodeNum(p.second);
			t.unite(p.first, p.second);
		}
		ans.push_back(num);
	}

	reverse(ans.begin(), ans.end());
	for (auto i = 0; i < (int)ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}

	return 0;
}