#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<long long>>ab(n, vector<long long>(2));
	for (int i = 0; i < n; i++)cin >> ab.at(i).at(0) >> ab.at(i).at(1);
	sort(ab.begin(), ab.end());
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (ab.at(i).at(1) <= m) {
			ans += ab.at(i).at(0) * ab.at(i).at(1);
			m -= ab.at(i).at(1);
		}
		else {
			ans += ab.at(i).at(0) * m;
			m -= m;
		}
	}
	cout << ans << endl;
}