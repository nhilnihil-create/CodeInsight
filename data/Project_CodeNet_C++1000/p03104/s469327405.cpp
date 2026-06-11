/*#include <iostream>
using namespace std;
const int N = 100010;
int n, length;
int step;
int a[N], vis[N];
int p;
long long k;
int dfs(int x) {
	if (vis[x]) return x;
	step++;
	vis[x] = 1;
	dfs(a[x]);
}

void dfs1(int x) {
	if (length && x == p) return;
	length++;
	dfs1(a[x]);
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	p = dfs(1);
	if (k <= step) {
		int now = 1;
		for (int i = 1; i <= k; i++) {
			now = a[now];
		}
		cout << now << endl;
	}
	else {
		dfs1(p);
		int sstep = (k - step) % length;
		int now = p;
		for (int i = 1; i <= sstep; i++) {
			now = a[now];
		}
		cout << now << endl;
	}

}


*/
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
int T, p1, p2, x, y;
char mp[N][N];
int f;
int ans;
void dfs(int mx, int my) {
	if (my == y + 1) dfs(mx + 1, 1);
	if (mx == x + 1) return;
	if (mp[mx][my] == '*') dfs(mx, my + 1);
	if (mp[mx][my] == '.' && mp[mx][my + 1] == '.') {
		ans += p2;
		dfs(mx, my + 2);
	}
	else if (mp[mx][my] == '.' && mp[mx][my + 1] != '.') {
		ans += p1;
		dfs(mx, my + 1);
	}
}

int main() {
	cin >> T;
	while (T--) {
		ans = 0;
		int sum = 0;
		getchar();
		cin >> x >> y >> p1 >> p2;
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				cin >> mp[i][j];
				if (mp[i][j] == '.') sum++;
			}
		}
		if (p1 * 2 < p2) {
			cout << p1 * sum << endl;
			continue;
		}
		dfs(1, 1);
		cout << ans << endl;
		memset(mp, 0, sizeof mp);
	}
}
*/
#include <iostream>
using namespace std;
typedef long long ll;
ll a, b;
ll solve(ll n) {
	ll t = n & 3;
	if (t & 1) return t / 2 ^ 1;
	return t / 2 ^ n;
}

int main() {
	cin >> a >> b;
	ll x = solve(a - 1), y = solve(b);
	ll ans = y ^ x;
	cout << ans << endl;
}