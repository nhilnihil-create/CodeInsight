#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;

class union_find_tree
{
private:
	int N;
	vector<int> parents, rank, node_cnt;

public:
	// n要素で初期化
	void init(int n)
	{
		parents.resize(n);
		for (int i = 0; i < n; i++)
			parents[i] = i;
		rank.resize(n, 0);
		node_cnt.resize(n, 1);
		N = n;
	}

	// 木の根を求める
	int find(int x)
	{
		if (parents[x] == x) {
			return x;
		} else {
			parents[x] = find(parents[x]);
			return parents[x];
		}
	}

	// xとyの属する集合を併合
	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y)
			return;

		if (rank[x] < rank[y]) {
			parents[x] = y;
			node_cnt[y] += node_cnt[x];
		} else {
			parents[y] = x;
			node_cnt[x] += node_cnt[y];
			if (rank[x] == rank[y])
				rank[x]++;
		}
	}

	// xとyが同じ集合に属するか否か
	bool same(int x, int y)
	{
		return find(x) == find(y);
	}

	// 親を取得
	int get_parent(int x)
	{
		return parents[x];
	}

	// ルートかどうか
	bool is_root(int x)
	{
		return parents[x] == x;
	}

	// グループの総数
	int number_of_groups()
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
			if (is_root(i))
				cnt++;
		return cnt;
	}

	// グループ内のノードの数
	int group_size(int x)
	{
		return node_cnt[find(x)];
	}
};

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int p[100000];
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}

	union_find_tree tree;
	tree.init(N);
	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		tree.unite(x, y);
	}

	int res = 0;
	for (int i = 0; i < N; i++)
		if (tree.same(i, p[i]))
			res++;

	printf("%d\n", res);

	return 0;
}
