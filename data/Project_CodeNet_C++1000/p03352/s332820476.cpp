#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	cin >> x;
	vector<int> ans = { 1 };
	for (int i = 2; i <= sqrt(x); i++) {
		int y = i * i;
		while (y <= x) {
			ans.push_back(y);
			y *= i;
		}
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	cout << ans.at(0) << endl;
		
}