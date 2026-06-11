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
using the = pair<int, int>;
using lthe = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

Vi color;
vector<vector<the> >G;

void dfs(int u, int r)
{
	for (the tnu : G[u]) {
		if (color[tnu.first] != -1)  continue;
		//cout << tnu.first << " " << r << endl;
		int t = (r + tnu.second) % 2;

		if (t == 0) {
			color[tnu.first] = 0;
		}
		else {
			color[tnu.first] = 1;
		}
		dfs(tnu.first, t);
	}
	return;
}


int main()
{
	int n;
	cin >> n;

	G.resize(n);
	rep(i, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		G[u].push_back({ v,w });
		G[v].push_back({ u,w });
	}

	color.resize(n, -1);
	color[0] = 0;

	dfs(0, 0);

	rep(i, n) cout << color[i] << endl;
}
