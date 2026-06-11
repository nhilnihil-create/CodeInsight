#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	vector<vector<int>> c(3, vector<int>(3));
	rep(i, 3) rep(j, 3) cin >> c[i][j];
	vector<int> a(3), b(3);
	rep(i, 3) a[i] = c[0][i] - b[0];
	rep(i, 3) b[i] = c[i][0] - a[0];
	bool ok = true;
	rep(i, 3) rep(j, 3) {
		if (b[i] + a[j] != c[i][j]) ok = false;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}