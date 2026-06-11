#include <iostream>
#include <vector>
using namespace std;

bool compare_second(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), compare_second);
	int ans = 0, b = 0;
	for (int i = 0; i < m; i++) {
		if (v[i].first < b) continue;
		b = v[i].second;
		ans++;
	}
	cout << ans << endl;
	return 0;
}