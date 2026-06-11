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

vector<vector<int>> check(100010, vector<int>());
vector<bool> flag(100010);
/*bool ok = true;

void dfs(int n, int p) {
	if (flag[n]) {
		ok = false;
		cout << n << endl;
		return;
	}
	flag[n] = true;
	for (int i : check[n]) {
		if (i == p) continue;
		else dfs(i, n);
	}
}*/

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n, m;
	cin >> n >> m;
	vector<vector<P>> graph(n, vector<P>());
	vector<int> l(m), r(m), d(m);
	vector<int> cnt(n);
	rep(i, m) {
		cin >> l[i] >> r[i] >> d[i];
		l[i]--; r[i]--;
		graph[l[i]].pb(P(r[i], d[i]));
		//if (d[i] > 0) check[l[i]].pb(r[i]);
		cnt[r[i]]++;
	}
	/*rep(i, n) {
		if (!flag[i]) {
			dfs(i, -1);
		}
	}
	if (!ok) {
		cout << "No" << endl;
		return 0;
	}*/
	vector<int> dis(n, -1);
	vector<bool> used(n);
	priority_queue<P> que;
	rep(i, n) {
		if (cnt[i] == 0) {
			que.push(P(0, i));
			dis[i] = 0;
			used[i] = true;
		}
	}
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int pf = p.first; int ps = p.second;
		flag[ps] = true;
		//cout << pf << ' ' << ps << endl;
		for (P i : graph[ps]) {
			if (dis[i.first] != -1 && dis[i.first] != dis[ps] + i.second) {
				cout << "No" << endl;
				return 0;
			}
			else {
				dis[i.first] = dis[ps] + i.second;
				if (!used[i.first]) {
					que.push(P(dis[i.first], i.first));
					used[i.first] = true;
				}
			}
		}
	}
	bool ans = true;
	rep(i, n) if (!flag[i]) ans = false;
	cout << (ans ? "Yes" : "No") << endl;
}