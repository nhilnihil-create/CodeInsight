#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<pair<int, int>>ab(m);
	for (int i = 0; i < m; i++) {
		cin >> ab[i].second >> ab[i].first;
	}
	sort(ab.begin(), ab.end());

	int ans = 0, now = -1e9;
	for (int i = 0; i < m; i++) {
		if (now <= ab[i].second) {
			ans++; now = ab[i].first;
		}
	}
	cout << ans << endl;

	return 0;
}