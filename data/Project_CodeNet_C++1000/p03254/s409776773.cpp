#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, x; cin >> n >> x;
	vector<int>a(n); for (auto&& i : a)cin >> i;
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (x >= a[i]) {
			x -= a[i]; ans++;
		}
	}
	if (x > 0&&ans==n) {
		ans--;
	}
	cout << ans << endl;

	return 0;
}