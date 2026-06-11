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

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<vector<int>> graph(n, vector<int>());
	vector<int> cnta(n), cntb(n);
	rep(i, m) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[u].pb(v);
		graph[v].pb(u);
		if (s[v] == 'A') cnta[u]++;
		else cntb[u]++;
		if (s[u] == 'A') cnta[v]++;
		else cntb[v]++;
	}
	queue<int> que;
	vector<bool> vis(n);
	int ng = 0;
	rep(i, n){
		if (cnta[i] == 0 || cntb[i] == 0) {
			que.push(i);
			ng++;
			vis[i] = true;
		}
	}
	while (!que.empty()) {
		int v = que.front(); que.pop();
		for (int i : graph[v]) {
			if (vis[i]) continue;
			if (s[v] == 'A') cnta[i]--;
			else cntb[i]--;
			if (cnta[i] == 0 || cntb[i] == 0) {
				que.push(i);
				ng++;
				vis[i] = true;
			}
		}
	}
	cout << (ng == n ? "No" : "Yes") << '\n';
}