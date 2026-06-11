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

ll solve(vector<P> p) {
	int n = p.size();
	vector<bool> vis(n);
	priority_queue<P, vector<P>, greater<P>> left;
	priority_queue<P> right;
	rep(i, n) {
		left.push(P(p[i].second, i));
		right.push(P(p[i].first, i));
	}
	int cnt = 0; ll res = 0; ll pl = 0; bool check = false;
	while (cnt < n) {
		bool ok = false;
		if (check) {
			while (!ok) {
				P q = left.top(); left.pop();
				if (!vis[q.second]) {
					ok = true;
					vis[q.second] = true;
				}
				res += max(pl - q.first, 0LL);
				pl -= max(pl - q.first, 0LL);
				cnt++;
			}
		}
		else {
			while (!ok) {
				P q = right.top(); right.pop();
				if (!vis[q.second]) {
					ok = true;
					vis[q.second] = true;
				}
				res += max(q.first - pl, 0LL);
				pl += max(q.first - pl, 0LL);
				cnt++;
			}
		}
		check = !check;
	}
	return res + abs(pl);
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	vector<P> p(n);
	rep(i, n) cin >> p[i].first >> p[i].second;
	ll ans = solve(p);
	rep(i, n) {
		p[i].first = -p[i].first;
		p[i].second = -p[i].second;
		swap(p[i].first, p[i].second);
	}
	cout << max(ans, solve(p)) << '\n';
}