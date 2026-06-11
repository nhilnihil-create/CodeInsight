#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main(void) {
	int n, m, i, j, k, l;
	ll p[1003][3], s, tr, ans = 0;

	cin >> n >> m;
	for (i = 0; i < n; i++) for (j = 0; j < 3; j++) {
		cin >> p[i][j];
	}

	for (i = 0; i < 8; i++) {
		vector<ll> t;
		for (j = 0; j < n; j++) {
			s = 0;
			for (k = 0; k < 3; k++) {
				if (((i >> k) & 1) == 1) s += p[j][k];
				else s -= p[j][k];
			}
			t.push_back(s);
		}
		sort(t.begin(), t.end(), greater<ll>());
		tr = 0;
		for (j = 0; j < m; j++) tr += t[j];
		ans = max(ans, tr);
	}

	cout << ans << endl;

	return 0;
}