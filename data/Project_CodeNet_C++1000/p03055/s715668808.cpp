#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <tuple>
#include <functional>
#define INF 1000000009
#define LINF 1000000000000000009
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;
template<class T> bool chmax(T &a, const T&b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T&b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

vector<vector<int>> graph(200010, vector<int>());

void dfs(int n, int par, int dis, vector<int> &res) {
	res[n] = dis;
	for (auto i : graph[n]) {
		if (i != par) {
			dfs(i, n, dis + 1, res);
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		graph[a[i]].push_back(b[i]);
		graph[b[i]].push_back(a[i]);
	}
	vector<int> x(n), y(n);
	dfs(0, -1, 0, x);
	int p = -1, d = -1;
	for (int i = 0; i < n; i++) {
		if (x[i] > d) {
			p = i; d = x[i];
		}
	}
	dfs(p, -1, 0, y);
	int ans = 0;
	for (auto i : y) chmax(ans, i);
	cout << (ans % 3 == 1 ? "Second" : "First") << endl;
}