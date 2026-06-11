#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> v(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	int ans = 0;	
	for (int i = 0; i < n; i++) {
		ans += max(v[i] - c[i], 0);
	}
	cout << ans << endl;
	return 0;
}