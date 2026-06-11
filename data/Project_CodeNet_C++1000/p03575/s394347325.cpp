#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)
#define MAX_N 1000
int par[MAX_N];  // 親
int rnk[MAX_N];  // 木の深さ
// n要素で初期化
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
}
// 木の根を求める
int find(int x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}
// xとyの属する集合を併合
void unite(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) par[x] = y;
	else {
		par[y] = x;
		if (rnk[x] ==rnk[y]) rnk[x]++;
	}
}
// xとyが同じ集合に属するか否か
bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	int N, M; cin >> N >> M;
	int v[2500][2];
	rep(i, M) {
		cin >> v[i][0] >> v[i][1];
		v[i][0]--; v[i][1]--;
	}
	int ans = 0;
	rep(i, M) {
		init(N);
		rep(j, M) {
			if (j == i) continue;
			unite(v[j][0], v[j][1]);
		}
		rep(j, N-1) {
			bool tmp = same(j, j+1);
			if (tmp == 0) {
				ans++; break;
			}
		}
	}
	cout << ans << endl;
}