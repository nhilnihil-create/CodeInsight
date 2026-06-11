#include<bits/stdc++.h>
using namespace std;
bool ok(string x, string y) {
	int mn = INT_MAX, mx = INT_MIN;
	int sz1 = (int)x.size(), sz2 = (int)y.size();
	for (int i = 0; i < sz1; ++i)
		mn = min(mn, (int)x[i]);
	for (int i = 0; i < sz2; ++i)
		mx = max(mx, (int)y[i]);
	return mn < mx ? 1 : 0;
}
int main() {
	string x, y; cin >> x >> y;
	if (ok(x, y) || x < y) cout << "Yes";
	else cout << "No";
	return 0;
}