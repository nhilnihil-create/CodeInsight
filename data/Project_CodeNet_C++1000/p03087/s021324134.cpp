#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, q; cin >> n >> q;
	string s; cin >> s;
	vector<int> accum(n + 1, 0);
	for (int i = 1; i < n; i++) {
		if (s[i - 1] == 'A' && s[i] == 'C') {
			accum[i + 1]++;
		}
		accum[i + 1] += accum[i];
	}
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		int ans = accum[r] - accum[l];
		cout << ans << endl;
	}
	return 0;
}