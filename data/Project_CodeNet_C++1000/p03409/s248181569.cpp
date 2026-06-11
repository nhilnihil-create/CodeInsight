#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	vector<pair<int, int>> red;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		red.push_back({ a,b });
	}
	vector<pair<int, int>> blue;
	for (int i = 0; i < n; i++) {
		int c, d; cin >> c >> d;
		blue.push_back({ c,d });
	}
	sort(blue.begin(), blue.end());

	vector<bool> used(n, false);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int bx = blue[i].first;
		int by = blue[i].second;
		int near_y = -1000;
		int near_j = -1;
		for (int j = 0; j < n; j++) {
			if (used[j]) continue;
			int rx = red[j].first;
			int ry = red[j].second;
			if (bx < rx) continue;
			if (by < ry) continue;
			if (near_y < ry) {
				near_j = j;
				near_y = ry;
			}
		}
		if (near_j != -1) {
			cnt++;
			used[near_j] = true;
		}
	}
	cout << cnt << endl;
    return 0;
}