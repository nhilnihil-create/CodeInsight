#define _USE_MATH_DEFINES
#include  <iostream>
#include  <algorithm>
#include  <climits>
#include  <vector>
#include  <string>
#include  <cstring>
#include  <stack>
#include  <queue>
#include  <cmath>
#include  <iomanip>
#include  <set>
#include  <map>
#include  <new>
#include <cstdint>
#include <cctype>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define lrep(i,n,m)  for(int i = n; i < m; i++)

using ll = long long;
using Vii = vector<vector<int> >;
using Gjudge = vector<vector<bool>>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vll = vector<vector<ll> >;
using Vs = vector<string>;
using Vb = vector<bool>;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Ti = tuple<int, int, int>;
using Tl = tuple<ll, ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const ll LINF = LLONG_MAX / 10000;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };


Vi color;
Vii G;
bool dfs(int u, int c)
{
	if (color[u] == 0 && c == 1) return false;
	if (color[u] == 1 && c == 0) return false;
	if (color[u] != -1) return true;
	color[u] = c;
	bool f = true;
	if (c == 0) {
		rep(nu, G[u].size()) {
			if (!dfs(G[u][nu], c + 1)) f = false;
		}
	}
	else {
		rep(nu, G[u].size()) {
			if (!dfs(G[u][nu], c - 1)) f = false;
		}
	}
	//if (!f) cout << "false" << endl;
	return f;
}

int main()
{
	int n, m;
	cin >> n >> m;
	G.resize(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	color.resize(n, -1);
	if (!dfs(0, 0)) {
		cout << ll(n) * (n - 1) / 2 - m << endl;
	}
	else {
		ll bsum = 0;
		rep(i, n) {
			if (color[i] == 0) bsum++;
		}
		cout << bsum * (n - bsum) - m << endl;
	}

	//rep(i, n) {
	//	cout << color[i] << endl;
	//}
}
