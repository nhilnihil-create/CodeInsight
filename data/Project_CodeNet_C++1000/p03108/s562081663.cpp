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

struct UFTree2 {
private:
	vector<int> mNode;
	vector<int> mRank;
	vector<int> mNodeNum;

public:
	UFTree2(int n) : mNode(n), mRank(n), mNodeNum(n)
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

	vector<pair<int, int>> bridge;
	for (auto i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		--A;
		--B;
		bridge.push_back({ A, B });
	}

	reverse(bridge.begin(), bridge.end());

	UFTree2 t(N);
	auto res = (ll)N * (N - 1) / 2;
	vector<ll> ans;
	ans.push_back(res);
	for (auto i = 0; i < M - 1; ++i)
	{
		auto& p = bridge[i];
		auto A = p.first;
		auto B = p.second;
		if (t.isSameSet(A, B))
		{
			ans.push_back(res);
			continue;
		}

		ll numA = t.getNodeNum(A);
		ll numB = t.getNodeNum(B);
		ll num = numA + numB;
		res += numA * (numA - 1) / 2;
		res += numB * (numB - 1) / 2;
		res -= num * (num - 1) / 2;
		t.unite(A, B);
		ans.push_back(res);
	}

	reverse(ans.begin(), ans.end());
	for (auto a : ans)
	{
		cout << a << endl;
	}

	return 0;
}