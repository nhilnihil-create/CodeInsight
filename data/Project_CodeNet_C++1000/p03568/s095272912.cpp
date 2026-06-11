#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a[10], b[10];
int cnt = 0, prod = 1;

void dfs(int i, int e) {
	if (i == e) {
		if (prod % 2 == 0) cnt++;
		return;
	}
	int prod0 = prod;

	prod = (prod0 * (a[i] - 1)) & 1;
	dfs(i + 1, e);
	prod = (prod0 * a[i]) & 1;
	dfs(i + 1, e);
	prod = (prod0 * (a[i] + 1)) & 1;
	dfs(i + 1, e);
}

int main() {
	int n; cin >> n;
	rep(i, 0, n) cin >> a[i];
	dfs(0, n);
	cout << cnt << endl;
}
