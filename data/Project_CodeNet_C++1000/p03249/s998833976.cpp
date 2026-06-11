#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	vector<ll> d(n);
	map<ll, int> mp;
	rep(i, n) {
		cin >> d[i];
		mp[d[i]] = i;
	}
	sort(all(d));
	vector<int> sz(n, 1);
	vector<P> ans;
	vector<vector<int>> graph(n, vector<int>());
	for (int i = n - 1; i >= 1; i--) {
		int v = mp[d[i]];
		ll dis = n - sz[v] * 2;
		ll par = d[i] - dis;
		ll idx = lower_bound(all(d), par) - d.begin();
		if (dis <= 0 || d[idx] != par) {
			cout << -1 << '\n';
			return 0;
		}
		ans.pb(P(mp[d[idx]] + 1, v + 1));
		graph[mp[d[idx]]].pb(v);
		graph[v].pb(mp[d[idx]]);
		sz[mp[d[idx]]] += sz[v];
	}
	int root = mp[d[0]];
	ll sum = 0;
	queue<P> que;
	vector<bool> vis(n);
	que.push(P(root, 0)); vis[root] = true;
	while (!que.empty()) {
		P p = que.front(); que.pop();
		int pf = p.first; int ps = p.second;
		sum += ps;
		for (int i : graph[pf]) {
			if (vis[i]) continue;
			que.push(P(i, ps + 1));
			vis[i] = true;
		}
	}
	if (sum != d[0]) cout << -1 << '\n';
	else for (P p : ans) cout << p.first << ' ' << p.second << '\n';
}