#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
	vector<vector<int>>pab(n, vector<int>(3,0));
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pab.at(i).at(0) = a + b;
		pab.at(i).at(1) = a;
		pab.at(i).at(2) = b;
	}
	sort(pab.begin(), pab.end());
	reverse(pab.begin(), pab.end());
	bool x = true;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (x) {
			ans += pab.at(i).at(1);
			x = false;
		}
		else {
			ans -= pab.at(i).at(2);
			x = true;
		}
	}
	cout << ans << endl;
}