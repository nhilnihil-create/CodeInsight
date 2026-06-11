#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
int bestd = -1, root, diam;
vector<int> E[200005];
void go(int x, int p = -1, int d = 0) {
	if (d > bestd) {
		bestd = d;
		root = x;
	}
	diam = max(diam, d);
	for (int y : E[x]) {
		if (y == p) continue;
		go(y, x, d + 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	go(1);
	go(root);
	printf(diam % 3 == 1 ? "Second\n" : "First\n");
}
