#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair<int, int>> v;
int n,m, ans;

int main() {
	cin >> n >> m;
	
	v.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i].second >> v[i].first;
	}

	sort(v.begin(), v.end());
	int t = 0;

	for (int i = 0; i < m; i++) {
		if (t <= v[i].second) {
			ans++;
			t = v[i].first;
		}
	}

	cout << ans << endl;

}