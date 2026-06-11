#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>a(n); for (auto&& x : a)cin >> x;
	sort(a.begin(), a.end());
	int an = a[n - 1], ar = a[0];
	long long d = abs(an - ar * 2);
	for (int i = 1; i < n - 1; i++) {
		if (d > abs(an - a[i] * 2)) { d = abs(an - a[i] * 2); ar = a[i]; }
	}
	cout << an << ' ' << ar << endl;
	return 0;
}