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

struct edge { int to, cost; };

vector<vector<edge>>tree;
vector<int>ans;
void dfs(int v, int clr, int p = -1) {
	rep(i, tree[v].size()) {
		int u = tree[v][i].to;
		if (u == p)continue;
		int nclr;
		if (tree[v][i].cost == 0)nclr = clr;
		else nclr = 1 - clr;
		ans[u] = nclr;
		dfs(u, ans[u], v);
	}
}

signed main() {
	int N;
	cin >> N;
	tree.resize(N);
	ans.resize(N);
	ans[0] = 0;
	rep(i, N - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		w %= 2;
		tree[u].push_back({ v,w });
		tree[v].push_back({ u,w });
	}
	dfs(0, 0);
	rep(i, N)cout << ans[i] << endl;
}