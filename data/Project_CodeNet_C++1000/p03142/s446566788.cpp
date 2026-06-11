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
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>());
	vector<int> deg(n);
	vector<int> a(n + m - 1), b(n + m - 1);
	rep(i, n + m - 1) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		graph[b[i]].push_back(a[i]);
		deg[a[i]]++;
	}
	queue<int> que;
	rep(i, n) if (deg[i] == 0) que.push(i);
	vector<int> order;
	while (!que.empty()) {
		int v = que.front(); que.pop();
		order.pb(v);
		for (int i : graph[v]) {
			deg[i]--;
			if (deg[i] == 0) que.push(i);
		}
	}
	reverse(all(order));
	vector<int> rorder(n);
	rep(i, n) rorder[order[i]] = i;
	vector<int> ans(n, -1);
	rep(i, n + m - 1) {
		chmax(ans[b[i]], rorder[a[i]]);
	}
	rep(i, n) {
		if (ans[i] == -1) cout << 0 << endl;
		else cout << order[ans[i]] + 1 << endl;
	}
}