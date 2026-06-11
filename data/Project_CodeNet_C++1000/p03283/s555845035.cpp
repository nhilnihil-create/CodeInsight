#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> g(n, vector<int>(n));
	rep(i, m) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		g[l][r]++;
	}
	vector<vector<int>> s(n + 1, vector<int>(n + 1));
	rep(i, n) rep(j, n) {
		s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + g[i][j];
	}
	rep(i, q) {
		int l, r;
		cin >> l >> r;
		cout << s[r][r] - s[r][l - 1] - s[l - 1][r] + s[l - 1][l - 1] << endl;
	}
	return 0;
}