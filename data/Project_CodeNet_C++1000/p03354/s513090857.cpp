#include <bits/stdc++.h>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define what_is(x) cerr << #x << " is " << x << endl;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

const int N = 1e5 + 4;
int parent[N], depth[N];

void init_sets(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		depth[i] = 0;
	}
}

int find_set(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find_set(parent[u]);
}

void union_sets(int u, int v) {
	u = find_set(u);
	v = find_set(v);
	if (u == v) return;
	if (depth[u] < depth[v]) swap(u, v);
	parent[v] = u;
	if (depth[u] == depth[v]) ++depth[u];
}

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	int n, m; scanf("%d%d", &n, &m);
	vi pos(n+1);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		pos[x] = i;
	}

	init_sets(n);
	while (m-- > 0) {
		int a, b;
		scanf("%d%d", &a, &b);
		union_sets(a, b);
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (find_set(i) == find_set(pos[i])) ++answer;
	}
	printf("%d\n", answer);
}
