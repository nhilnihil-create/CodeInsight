#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	vector<vector<int>> c(3, vector<int>(3));
	rep(i, 3) rep(j, 3) cin >> c[i][j];
	vector<int> C(3);
	rep(i, 3) rep(j, 3) C[i] += c[i][j];
	rep(a1, 101) rep(a2, 101) rep(a3, 101) {
		int A = a1 + a2 + a3;
		bool ok = true;
		rep(l, 3) {
			int b = C[l] - A;
			int tb = b / 3;
			if (b < 0 || b % 3 != 0) ok = false;
			if (tb < 0 || tb > 100) ok = false;
			if (a1 + tb != c[l][0] && a2 + tb != c[l][1] && a3 + tb != c[l][2]) ok = false;
		}
		if (ok) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}