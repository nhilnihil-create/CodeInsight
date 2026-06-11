#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
#define int long long
int par[200020];
int siz[200020];
int ans[200020];
int a[100010], b[100010];
int root(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = root(par[x]);
	}
}
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		par[i] = i;
		siz[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
	}
	ans[m] = (n - 1) * n / 2;
	for (int i = m - 1; i > 0; i--) {
		int x, y;
		x = root(a[i]);
		y = root(b[i]);
		int co = siz[x] * (siz[x] - 1) / 2 + siz[y] * (siz[y] - 1) / 2;
		if (x != y) {
			par[y] = x;
			siz[x] += siz[y];
			siz[y] = siz[x];
			ans[i] = ans[i + 1] - siz[x] * (siz[x] - 1) / 2 + co;
		}
		else {
			ans[i] = ans[i + 1];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
