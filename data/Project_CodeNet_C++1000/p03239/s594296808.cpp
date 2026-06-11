#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, t;
	cin >> n >> t;
	vector<vector<int>>ct(0, vector<int>(2));
	for (int i = 0; i < n; i++) {
		int c1, t1;
		cin >> c1 >> t1;
		if (t1 <= t)ct.push_back({ c1,t1 });
	}
	if (ct.size() == 0) {
		cout << "TLE" << endl;
		return 0;
	}
	sort(ct.begin(), ct.end());
	cout << ct.at(0).at(0) << endl;
}