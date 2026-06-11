#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
#define int long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define dup(x,y) (((x)+(y)-1)/(y))
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
const long double PI = (acos(-1));


struct UnionFind {
	vector<int> d; // d[i]:iの親の番号　(例) d[3] = 2 : 3の親が2 d[3] = -3 : 3は根で、その連結成分のサイズは3

	UnionFind(int N) : d(N, -1) {} // 負なら根である 非負なら子である

	int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (d[x] < 0) return x; //負なら根であるから根を返す
		return d[x] = root(d[x]);
	}

	bool unite(int x, int y) { // xとyの木を併合
		int rx = root(x); //xの根をrx
		int ry = root(y); //yの根をry
		if (rx == ry) return false; //xとyの根が同じ(=同じ木にある)時はそのまま
		if (d[rx] > d[ry])swap(rx, ry); //木のサイズが大きいほうにくっつける
		d[rx] += d[ry]; //サイズが上乗せされる
		d[ry] = rx; //yの根はxになる
		return true;
	}

	bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
	int size(int x) {
		return -d[root(x)];
	}
};


signed main() {
	int N, M;
	cin >> N >> M;
	UnionFind tree(N);
	rep(i, M) {
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		tree.unite(x, y);
	}
	set<int>se;
	rep(i, N)se.insert(tree.root(i));
	int ans = se.size();
	cout << ans << endl;
}