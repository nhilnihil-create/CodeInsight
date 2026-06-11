#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	
	vector<pair<int, int>> id;
	vector<vector<pair<int, int>>> prefecture(n);
	for (int i = 0; i < m; i++) {
		int p, y; cin >> p >> y;
		id.push_back({ --p, --y });
		prefecture[p].push_back({ y,i });
	}
	for (int i = 0; i < prefecture.size(); i++) {
		sort(prefecture[i].begin(), prefecture[i].end());
		for (int j = 0; j < prefecture[i].size(); j++) {
			id[prefecture[i][j].second].second = j;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << setw(6) << setfill('0') << id[i].first + 1 << setw(6) << setfill('0') << id[i].second + 1 << endl;
	}
	return 0;
}