#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}
template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}

struct UnionFind {
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

	UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
		for (int i = 0; i < N; i++) par[i] = i;
	}

	int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) { // xとyの木を併合
		int rx = root(x); //xの根をrx
		int ry = root(y); //yの根をry
		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
	}

	bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};


signed main(void) {
	int N, M;
	cin >> N >>M;
	UnionFind u(N);
	vector<int>p(N);
	rep(i, N) {
		int inp;
		cin >> inp;
		p[i] = inp - 1;
	}
	int x, y;
	rep(i, M) {
		cin >> x >> y;
		x--;
		y--;
		u.unite(x, y);
	}
	int ans = 0;
	rep(i, N) {
		if (u.same(i,p[i]))ans++;
	}
	print(ans);
}
