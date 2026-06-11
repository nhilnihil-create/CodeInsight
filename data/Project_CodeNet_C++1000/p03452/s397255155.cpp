#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());
#define PAU system("pause")

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 28);
const ll LINF = 1e18;
const double PI = acos(-1);

class UnionFindTree {
public:
	int treeCnt; //ツリーの数
	vi rank, p; //rank => 根の高さ, p => 親
	vi num; //木の要素数
	vi diff_weight;
	UnionFindTree() {}
	UnionFindTree(int size) {
		rank.resize(size, 0);
		p.resize(size, 0);
		num.assign(size, 1);
		diff_weight.assign(size, 0);
		treeCnt = 0;
		REP(i, size) {
			makeset(i);
		}
	}

	void makeset(int x) {
		p[x] = x;
		rank[x] = 0;
		treeCnt++;
	}

	//同じ木に属しているか判定
	bool isSame(int x, int y) {
		return root(x) == root(y);
	}

	//木と木を繋ぐ処理をする。
	// weight(y) - weight(x) = w となるように link する
	void link(int x, int y, int w) {
		w += weight(x); w -= weight(y);
		x = root(x);
		y = root(y);
		if (x == y) {
			return;
		}
		if (rank[x] < rank[y]) {
			swap(x, y); w = -w;
		}

		//yのrootをxのrootの下にくっつける
		if (rank[x] == rank[y]) ++rank[x];
		p[y] = x;
		diff_weight[y] = w;
		treeCnt--;
	}


	//xが属している木の根を探る
	int root(int x) {
		if (p[x] == x) return x;
		int r = root(p[x]);
		diff_weight[x] += diff_weight[p[x]];
		return p[x] = root(p[x]);
	}

	int weight(int x) {
		root(x);//あらかじめ経路圧縮しておく
		return diff_weight[x];
	}

	int diff(int x, int y) {
		return weight(y) - weight(x);
	}

	int countTree() {
		return treeCnt;
	}

	int getNum(int a) {
		return num[root(a)];
	}
};


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	UnionFindTree uft(N);
	REP(i, M) {
		int l, r, d;
		cin >> l >> r >> d;
		l--; r--;
		if (uft.isSame(l, r)) {
			if (uft.diff(l, r) != d) {
				cout << "No" << endl;
				PAU;
				return 0;
			}
			else continue;
		}
		uft.link(l, r, d);
	}
	cout << "Yes" << endl;
	PAU;
	return 0;
}
