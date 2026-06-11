#include <bits/stdc++.h>

#define N 300010 

using namespace std;

char *p1, *p2, buf[100000];

#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1 ++ )

int rd() {
	int x = 0, f = 1;
	char c = nc();
	while (c < 48) {
		if (c == '-')
			f = -1;
		c = nc();
	}
	while (c > 47) {
		x = (((x << 2) + x) << 1) + (c ^ 48), c = nc();
	}
	return x * f;
}

vector <int> v[N];

bool vis[N];

int main() {
	int h = rd(), w = rd(), n = rd();
	for (int i = 1; i <= n; i ++ ) {
		int x = rd(), y = rd();
		v[y].push_back(x);
	}

	for (int i = 1; i <= w; i ++ ) {
		v[i].push_back(h + 1);
	}
	sort(v[1].begin(), v[1].end());

	int ans = v[1][0] - 1;
	int t = 0;
	for (int i = 2; i <= w; i ++ ) {
		sort(v[i].begin(), v[i].end());
		int s = v[i].size(), m = 0;
		for (int k = 0; k < s; k ++ ) {
			if (v[i][k] <= i + t) {
				vis[v[i][k]] = 1;
				m = max(v[i][k], m);
			}
			else if (vis[v[i][k] - 1]) {
				vis[v[i][k]] = 1;
				m = max(v[i][k], m);
			}
			else {
				ans = min(ans, v[i][k] - 1);
				break;
			}
 		}
		t = max(t, m - i + 1);
	}
	cout << ans << endl ;
	return 0;
}