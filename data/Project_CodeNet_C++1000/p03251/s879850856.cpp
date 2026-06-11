#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m, X, Y; cin >> n >> m >> X >> Y;
	vector<int> x(n), y(m);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	bool war = true;
	for (int z = X + 1; z <= Y; z++) {
		if (x[n - 1] < z && z <= y[0]) war = false;
	}
	if (war) cout << "War" << endl;
	else cout << "No War" << endl;
	return 0;
}