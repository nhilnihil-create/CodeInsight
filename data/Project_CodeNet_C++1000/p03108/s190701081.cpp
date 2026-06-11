#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)
#define MAX_N 100000
int par[MAX_N];  // 親
int rnk[MAX_N];  // 木の深さ
int mem[MAX_N];  // グループの要素数
// n要素で初期化
void init(ll n) {
	for (ll i = 0; i < n; i++) {
		par[i] = i; rnk[i] = 0; mem[i] = 1;
	}
}
// 木の根を求める
ll find(ll x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}
// xとyの属する集合を併合
void unite(ll x, ll y) {
	x = find(x); y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) {
		par[x] = y; mem[y] += mem[x];
	} else {
		par[y] = x; mem[x] += mem[y];
		if (rnk[x] == rnk[y]) rnk[x]++;
	}
}
// xとyが同じ集合に属するか否か
bool same(ll x, ll y) {
	return find(x) == find(y);
}
// グループのサイズ
ll size(ll x) {
	return mem[find(x)];
}

int main() {
	ll N, M; cin >> N >> M;
	ll A[100000], B[100000];
	ll ans[100000];
	rep(i, M) {
		cin >> A[i]; A[i]--;
		cin >> B[i]; B[i]--;
	}
	init(N);
	ll a = N * (N-1) / 2;
	for (int i = M-1; i >= 0; i--) {
		if (i == M-1) {
			ans[i] = a; continue;
		}
		if (same(A[i+1], B[i+1])) {
			ans[i] = ans[i+1];
		} else {
			ans[i] = ans[i+1] - size(A[i+1])*size(B[i+1]);
			unite(A[i+1], B[i+1]);
		}
	}
	rep(i, M) {
		cout << ans[i] << endl;
	}
}