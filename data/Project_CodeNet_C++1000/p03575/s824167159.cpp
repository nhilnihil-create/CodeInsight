#include <vector>
#include <iostream>
using namespace std;

class UnionFind {
private:
	std::vector<int> pre;
	std::vector<int> siz;
	std::vector<int> rank;
	int cnt;
	int root(int x);
public:
	UnionFind(int n);
	void unite(int x, int y);
	int size(int x);
	bool same(int x, int y);
	int get_cnt();
};

UnionFind::UnionFind(int n) : pre(n), siz(n), rank(n) {
	for (int i = 0; i < pre.size(); ++i) {
		pre.at(i) = i;
		siz.at(i) = 1;
		rank.at(i) = 0;
	}
	cnt = n;
}

int  UnionFind::root(int x) {
	if (pre.at(x) == x) return x;
	else return pre.at(x) = root(pre.at(x));
}

void UnionFind::unite(int x, int y) {
	int root_x = root(x);
	int root_y = root(y);
	if (root_x == root_y) return;
	if (rank.at(root_x) < rank.at(root_y)) {
		siz.at(root_y) += siz.at(root_x);
		pre.at(root_x) = root_y; 
	} 
	else{
		siz.at(root_x) += siz.at(root_y);
		pre.at(root_y) = root_x;
		if (rank.at(root_x) == rank.at(root_y))
			rank.at(x)++;
	}
	cnt--;
}

int UnionFind::size(int x) {
	return siz.at(root(x));
}

bool UnionFind::same(int x, int y) {
	return root(x) == root(y);
}

int UnionFind::get_cnt() {
	return cnt;
}

int main(void) {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> ab(m);
	for (int i = 0; i < m; ++i) {
		cin >> ab.at(i).first >> ab.at(i).second;
		ab.at(i).first--;
		ab.at(i).second--;
	}

	int ans = 0;
	for (int i = 0; i < m; ++i) {
		UnionFind uni(n);
		for (int j = 0; j < m; ++j)
			if (i != j)
				uni.unite(ab.at(j).first, ab.at(j).second);
		if (uni.get_cnt() == 2)
			ans++;
	}

	cout << ans;
}