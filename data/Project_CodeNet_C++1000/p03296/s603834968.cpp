#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>a(n); for (auto&& x : a)cin >> x;

	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		if (a[i + 1] == a[i])ans++, i++;
	}
	cout << ans << endl;

	return 0;
}