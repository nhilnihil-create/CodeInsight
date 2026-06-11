#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>a(n); for (auto&& x : a)cin >> x;
	sort(a.begin(), a.end());
	int aN = a[n - 1], aR = a[0];
	long long dis = 1e9;
	for (int i = 1; i < n - 1; i++) {
		if (dis > abs(a[i] * 2 - aN)) {
			dis = abs(a[i] * 2 - aN);
			aR = a[i];
		}
	}
	cout << aN << ' ' << aR << endl;

	return 0;
}