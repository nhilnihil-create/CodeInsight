#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

#define rep(i, a, b) for (int i = (a); i < (b); i++)

int n, q;
char t[maxn], d[maxn];
string s;

int cal(int u) {
	rep(i, 0, q) {
		if (u == -1 || u == n) return u;
		if (t[i] == s[u]) {
			if (d[i] == 'L') {
				u--;
			} else {
				u++;
			}
		}
	}
	return u;
}

int main() {
	cin >> n >> q;
	
	cin >> s;
	
	rep(i, 0, q) {
		cin >> t[i] >> d[i];
	}
	
	int l = 0, r = n - 1, found1 = -1, found2 = n;
	
	while (l <= r) {
		int m = (l + r) >> 1;
		int pos = cal(m);
		if (pos == -1) {
			found1 = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	
	l = 0, r = n - 1;
	
	while (l <= r) {
		int m = (l + r) >> 1;
		int pos = cal(m);
		if (pos == n) {
			found2 = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	
	int ans = n - (found1 + 1) - (n - found2);
	
	cout << ans;
	
	return 0;
}