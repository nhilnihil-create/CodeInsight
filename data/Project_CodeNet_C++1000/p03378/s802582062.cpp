#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, m, x; cin >> n >> m >> x;
	vector<bool> a(n + 1);
	for (int i = 0; i < m; i++) {
		int j; cin >> j;
		a.at(j) = true;
	}
	int cnt = 0;
	for (int i = x + 1; i < n; i++) {
		if (a.at(i)) cnt++;
	}
	int cnt2 = 0;
	for (int i = x - 1; i > 0; i--) {
		if (a.at(i)) cnt2++;
	}
	cout << min(cnt, cnt2) << endl;
}