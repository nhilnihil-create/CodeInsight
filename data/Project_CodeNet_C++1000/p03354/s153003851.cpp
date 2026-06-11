
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getint(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld %lld";
	}

	if (scanf(fmt, &a, &b, &c) < 0) {
		printf("g3int Error\n");
	}
}

static void ABC097D();

#if 1
int main()
{
	ABC097D();
	fflush(stdout);
	return 0;
}
#endif

class UnionFindTree
{
protected:
	int* _par = 0;
	int* _rank = 0;
	int* _count = 0;

	void init(int size) {
		_par = new int[size];		//	親ノード
		_rank = new int[size];		//	高さ
		_count = new int[size];		//	結合グループの要素数

		for (int i = 0; i < size; i++) {
			_par[i] = i;
			_rank[i] = 0;
			_count[i] = 1;
		}
	}

public:
	UnionFindTree(int size = 10) {
		init(size);
	}

	~UnionFindTree() {
		delete[] _par;
		delete[] _rank;
		delete[] _count;
	}

	//	木の根を求める
	int find(int x) {
		if (_par[x] == x) {
			return x;
		}
		else {
			return(_par[x] = find(_par[x]));
		}
	}

	//	x と y の属する集合を併合
	void Unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			//	すでに同じ集合だった
			return;
		}

		if (_rank[x] < _rank[y]) {
			//	数をまず加算しておく
			_count[y] = _count[y] + _count[x];
			_par[x] = y;
		}
		else {
			//	数をまず加算しておく
			_count[x] = _count[y] + _count[x];

			_par[y] = x;
			if (_rank[x] == _rank[y]) {
				_rank[x]++;
			}
		}
	}

	bool IsUnion(int x, int y) {
		return (find(x) == find(y));
	}

	int count(int x) {
		return _count[find(x)];
	}
};

static void ABC097D()
{
	int N, M;
	getint(N, M);

	std::vector<int> pn(N);
	for (int i = 0; i < N; i++) {
		getint(pn[i]);
		pn[i]--;
	}

	UnionFindTree uf(N);
	for (int i = 0; i < M; i++) {
		int x, y;
		getint(x, y); x--; y--;
		uf.Unite(x, y);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (uf.IsUnion(i, pn[i])) {
			ans++;
		}
	}
	printf("%d\n", ans);
}
