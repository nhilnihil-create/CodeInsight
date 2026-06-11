#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <utility>
#define INF 1000000009
#define LINF 1000000000000000009
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;
typedef pair<ll, double> PD;
//ll mod = 1000000007;
//ll mod = 998244353;

vector<int> parent(100010);
vector<int> ran(100010);

void init(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		ran[i] = 0;
	}
}

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (ran[x] < ran[y]) parent[x] = y;
	else {
		parent[y] = x;
		if (ran[x] == ran[y]) ran[x]++;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	init(n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> x(m), y(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		x[i]--; y[i]--;
		unite(x[i], y[i]);
	}
	int ans = 0;
	vector<set<int>> st(n, set<int>());
	for (int i = 0; i < n; i++) {
		st[find(i)].insert(a[i] - 1);
	}
	for (int i = 0; i < n; i++) {
		if (st[find(i)].count(i)) ans++;
	}
	cout << ans << endl;
}