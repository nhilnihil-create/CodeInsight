#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<vector<ll>>xyh(0, vector<ll>(3));
	for (int i = 0; i < n; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		if (z != 0) xyh.push_back({ x, y, z });
	}
	if (xyh.size() == 1) {
		cout << xyh.at(0).at(0) << " " << xyh.at(0).at(1) << " " << xyh.at(0).at(2) << endl;
		return 0;
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			ll cx = i;
			ll cy = j;
			ll ch = abs(cx - xyh.at(0).at(0)) + abs(cy - xyh.at(0).at(1)) + xyh.at(0).at(2);
			bool b = false;
			for (int k = 0; k < xyh.size(); k++) {
				if (xyh.at(k).at(2) == 0)continue;
				if (ch != abs(cx - xyh.at(k).at(0)) + abs(cy - xyh.at(k).at(1)) + xyh.at(k).at(2)) {
					b = true;
					break;
				}
			}
			if (!b) {
				cout << cx << " " << cy << " " << ch << endl;
				return 0;
			}
			else continue;
		}
	}
}